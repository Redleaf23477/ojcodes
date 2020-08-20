// Disclaimer: This code is a hybrid between old CP1-2-3 implementation of
// Edmonds Karp's algorithm -- re-written in OOP fashion and the fast
// Dinic's algorithm implementation by
// https://github.com/jaehyunp/stanfordacm/blob/master/code/Dinic.cc
// This code is written in modern C++17 standard
// Cherry-picked from cp3

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef tuple<int, ll, ll> edge;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 1e18;                             // large enough

class max_flow {
private:
  int V;
  vector<edge> EL;
  vector<vi> AL;
  vi d, last;
  vector<ii> p;

  bool BFS(int s, int t) {                       // find augmenting path
    d.assign(V, -1); d[s] = 0;
    queue<int> q({s});
    p.assign(V, {-1, -1});                       // record BFS sp tree
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (u == t) break;                         // stop as sink t reached
      for (auto &idx : AL[u]) {                  // explore neighbors of u
        auto &[v, cap, flow] = EL[idx];          // stored in EL[idx]
        if ((cap-flow > 0) && (d[v] == -1))      // positive residual edge
          d[v] = d[u]+1, q.push(v), p[v] = {u, idx}; // 3 lines in one!
      }
    }
    return d[t] != -1;                           // has an augmenting path
  }

  ll DFS(int u, int t, ll f = INF) {             // traverse from s->t
    if ((u == t) || (f == 0)) return f;
    for (int &i = last[u]; i < (int)AL[u].size(); ++i) { // from last edge
      auto &[v, cap, flow] = EL[AL[u][i]];
      if (d[v] != d[u]+1) continue;              // not part of layer graph
      if (ll pushed = DFS(v, t, min(f, cap-flow))) {
        flow += pushed;
        auto &rflow = get<2>(EL[AL[u][i]^1]);     // back edge
        rflow -= pushed;
        return pushed;
      }
    }
    return 0;
  }

public:
  max_flow(int initialV) : V(initialV) {
    EL.clear();
    AL.assign(V, vi());
  }

  // if you are adding a bidirectional edge u<->v with weight w into your
  // flow graph, set directed = false (default value is directed = true)
  void add_edge(int u, int v, ll w, bool directed = true) {
    if (u == v) return;                          // safeguard: no self loop
    EL.emplace_back(v, w, 0);                    // u->v, cap w, flow 0
    AL[u].push_back(EL.size()-1);                // remember this index
    EL.emplace_back(u, directed ? 0 : w, 0);     // back edge
    AL[v].push_back(EL.size()-1);                // remember this index
  }

  ll dinic(int s, int t) {
    ll mf = 0;                                   // mf stands for max_flow
    while (BFS(s, t)) {                          // an O(V^2*E) algorithm
      last.assign(V, 0);                         // important speedup
      while (ll f = DFS(s, t))                   // exhaust blocking flow
        mf += f;
    }
    return mf;
  }
};

int R, C, m;
int vn, s, t;
max_flow dinic(0);

void init()
{
    cin >> R >> C >> m;
    // 0 ~ R*C-1 : front
    // R*C ~ 2*R*C-1 : back
    // 2*R*C : s
    // 2*R*C+1 : t
    vn = 2+2*R*C, s = 2*R*C, t = s+1;
    dinic = max_flow(vn);
    // s -> banks
    for(int _ = 0; _ < m; _++)
    {
        int r, c; cin >> r >> c;
        r--, c--;
        dinic.add_edge(s, r*C+c, 1);
    }
    // (r, 0) and (r, C-1) -> t
    for(int r = 0; r < R; r++)
    {
        dinic.add_edge(R*C+r*C, t, 1);
        dinic.add_edge(R*C+r*C+C-1, t, 1);
    }
    // (0, c) and (R-1, c) -> t
    for(int c = 0; c < C; c++)
    {
        dinic.add_edge(R*C+c, t, 1);
        dinic.add_edge(R*C+R*C-C+c, t, 1);
    }
    // within vertices
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
        {
            int u = r*C+c, v = R*C+u;
            dinic.add_edge(u, v, 1);
        }
    // u, d, l, r
    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
    for(int r = 0; r < R; r++)
        for(int c = 0; c < C; c++)
            for(int d = 0; d < 4; d++)
            {
                int rr = r+dr[d], cc = c+dc[d];
                if(!(0 <= rr && rr < R && 0 <= cc && cc < C)) continue;
                int u = R*C+r*C+c, v = rr*C+cc;
                dinic.add_edge(u, v, 1);
            }
}

void process()
{
    if(dinic.dinic(s, t) == m) cout << "possible" << endl;
    else cout << "not possible" << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        init();
        process();
    }
    cout.flush();
}
