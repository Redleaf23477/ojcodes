// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);

using namespace std;
using LL = long long int;

////////////////////////////////////////////

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

////////////////////////////////////////////

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n;
vector<int> a, b;

void init() {
    cin >> n;
    a.resize(n), b.resize(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
}

void process() {
    const int INF = (int)1e9;
    int s = n, t = n+1;
    Dinic<int> dinic(n, s, t);
    for (int i = 0; i < n; i++) {
        if (b[i] > 0) { // s-> i
            dinic.add_edge(s, i, b[i]);
        } else { // i -> t
            dinic.add_edge(i, t, -b[i]);
        }
        // i -> j if j is the nearest on left such that a[i] % a[j] == 0
        vector<bool> vis(101, false);
        for (int j = i-1; j >= 0; j--) {
            if (a[i] % a[j] == 0 && !vis[a[j]]) {
                vis[a[j]] = true;
                dinic.add_edge(i, j, INF);
            }
        }
    }
    int sum = 0; {
        for (auto x : b) sum += (x>0)*x;
    }
    cout << sum - dinic.flow() << endl;
}

