#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

// I trust DINIC

template <class T>
struct Dinic {
  static const T INF = 0x3f3f3f3f;
  struct Edge {
    int v;
    T f;
    int re;
    Edge(int _v, T _f, int _re) : v(_v), f(_f), re(_re) {}
  };
  int n, s, t;
  vector<vector<Edge>> E;
  vector<int> level, now;
  Dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t), E(_n), level(_n), now(_n) {}
  int add_edge(int u, int v, T f, bool bidirectional = false) {
    E[u].emplace_back(v, f, E[v].size());
    E[v].emplace_back(u, 0, E[u].size() - 1);
    if (bidirectional) {
      E[v].emplace_back(u, f, E[u].size() - 1);
    }
    return E[u].size() - 1;
  }
  bool BFS() {
    fill(level.begin(), level.end(), -1);
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
      fill(now.begin(), now.end(), 0);
      while (temp = DFS(s, INF)) {
        res += temp;
        res = min(res, INF);
      }
    }
    return res;
  }
};

//////////////////////

void solve() {
    int R, C; cin >> R >> C;
    vector<vector<int>> arr(R, vector<int>(C));
    int one = 0;
    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> arr[r][c];
            one += arr[r][c];
        }
    }
    if (one % R != 0) {
        cout << -1 << "\n"; return;
    }
    int one_per_row = one / R;
    // FLOW
    // 0 - R-1: rows
    // R - R+C-1: cols
    // R+C - R+C+1: s, t
    int S = R+C, T = R+C+1;
    int expected_flow = 0;
    vector<int> overflow, underflow;
    Dinic<int> dinic(R+C+2, S, T);
    for (int r = 0; r < R; r++) {
        int row_cnt = 0;
        for (int c = 0; c < C; c++) {
            row_cnt += arr[r][c];
        }
        if (row_cnt > one_per_row) {
            overflow.emplace_back(r);
            expected_flow += row_cnt - one_per_row;
            dinic.add_edge(S, r, row_cnt - one_per_row);
            for (int c = 0; c < C; c++) {
                if (arr[r][c] == 1) {
                    // reuse: memory edge index
                    arr[r][c] = dinic.add_edge(r, R + c, 1);
                } else {
                    arr[r][c] = -1;
                }
            }
        } else if (row_cnt < one_per_row) {
            underflow.emplace_back(r);
            dinic.add_edge(r, T, one_per_row - row_cnt);
            for (int c = 0; c < C; c++) {
                if (arr[r][c] == 0) {
                    // reuse: memory edge index
                    arr[r][c] = dinic.add_edge(R + c, r, 1);
                } else {
                    arr[r][c] = -1;
                }
            }
        }
    }
    int f = dinic.flow();
    if (f == expected_flow) {
        vector<vector<int>> enter(C), leave(C);
        for (auto r : overflow) {
            for (int c = 0; c < C; c++) {
                if (arr[r][c] != -1) {
                    if (dinic.E[r][arr[r][c]].f == 0) enter[c].emplace_back(r);
                }
            }
        }
        for (auto r : underflow) {
            for (int c = 0; c < C; c++) {
                if (arr[r][c] != -1) {
                    if (dinic.E[R+c][arr[r][c]].f == 0) leave[c].emplace_back(r);
                }
            }
        }
        cout << f << "\n";
        for (int c = 0; c < C; c++) {
            for (size_t i = 0; i < enter[c].size(); i++) {
                cout << enter[c][i] + 1 << " " << leave[c][i] + 1 << " " << c + 1 << "\n";
            }
        }
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

