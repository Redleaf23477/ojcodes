#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using TII = tuple<int,int>;

template <class T>
struct Dinic {
  static const int MAXV = 10000;
  static const T INF = 0x3f3f3f3f;
  struct Edge {
    int v;
    T f;
    int re;
    Edge(int _v, T _f, int _re) : v(_v), f(_f), re(_re) {}
  };
  int n, s, t, level[MAXV];
  vector<Edge> E[MAXV];
  int now[MAXV];
  Dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {}
  void add_edge(int u, int v, T f, bool bidirectional = false) {
    E[u].emplace_back(v, f, E[v].size());
    E[v].emplace_back(u, 0, E[u].size() - 1);
    if (bidirectional) {
      E[v].emplace_back(u, f, E[u].size() - 1);
    }
  }
  bool BFS() {
    memset(level, -1, sizeof(level));
    queue<int> que;
    que.emplace(s);
    level[s] = 0;
    while (not que.empty()) {
      int u = que.front();
      que.pop();
      for (auto it : E[u]) {
        if (it.f > 0 and level[it.v] == -1) {
          level[it.v] = level[u] + 1;
          que.emplace(it.v);
        }
      }
    }
    return level[t] != -1;
  }
  T DFS(int u, T nf) {
    if (u == t) return nf;
    T res = 0;
    while (now[u] < E[u].size()) {
      Edge &it = E[u][now[u]];
      if (it.f > 0 and level[it.v] == level[u] + 1) {
        T tf = DFS(it.v, min(nf, it.f));
        res += tf;
        nf -= tf;
        it.f -= tf;
        E[it.v][it.re].f += tf;
        if (nf == 0) return res;
      } else
        ++now[u];
    }
    if (not res) level[u] = -1;
    return res;
  }
  T flow(T res = 0) {
    while (BFS()) {
      T temp;
      memset(now, 0, sizeof(now));
      while (temp = DFS(s, INF)) {
        res += temp;
        res = min(res, INF);
      }
    }
    return res;
  }
};

///////////////////////////////////

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n >> ws;
    int en = 0;
    // s: 0, t: n+1
    Dinic<int> dinic_base(n+2, 0, n+1);
    for (int u = 1; u <= n; u++) {
        string buff; getline(cin, buff);
        stringstream ss(buff);
        if (buff[0] == '*') {
            char ch; ss >> ch;
            int v; ss >> v;
            if (v == 1) v = n+1;
            dinic_base.add_edge(u, v, 10004);
        } else {
            int k; ss >> k;
            en += k;
            while (k--) {
                int v; ss >> v;
                if (v == 1) v = n+1;
                dinic_base.add_edge(u, v, 1);
            }
        }
    }

    int low = 0, high = en+1, mid, ans = 1;
    while (low <= high) {
        mid = (low + high) / 2;
        Dinic<int> dinic = dinic_base;
        dinic.add_edge(0, 1, mid);
        int f = dinic.flow();
        if (f == mid) ans = mid, low = mid + 1;
        else { ans = f; break; }
    }
    if (ans == en + 1) cout << "*\n";
    else cout << ans + 1 << "\n";
}

