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
  max_flow(int initialV=0) : V(initialV) {
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

int s, t;
ll n; 
double d;
vector<tuple<ll,ll,ll,ll>> arr;

void init()
{
    cin >> n >> d;
    arr.resize(n);
    for(int i = 0; i < n; i++)
    {
        ll x, y, p, m; cin >> x >> y >> p >> m;
        arr[i] = make_tuple(x, y, p, m);
    }
}

double pw2(double x) { return x * x; }

void process()
{
    vector<int> ans;
    // 0-(n-1) : in
    // n-(2*n-1) : out
    // 2*n : s
    // 2*n+1 : t
    int s = 2*n, t = s+1;
    for(int x = 0; x < n; x++)
    {
        max_flow dinic(2*n+2);
        ll tot = 0;
        for(int i = 0; i < n; i++)
        {
            auto [x, y, p, m] = arr[i];
            tot += p;
            // s -> in
            dinic.add_edge(s, i, p);
            // in -> out
            dinic.add_edge(i, n+i, m);
            // out -> neighbor
            for(int j = i+1; j < n; j++)
            {
                auto [x2, y2, _, __] = arr[j];
                if(pw2(x-x2)+pw2(y-y2) <= pw2(d))
                    dinic.add_edge(n+i, j, INF), dinic.add_edge(n+j, i, INF);
            }
        }
        // x -> t
        dinic.add_edge(x, t, INF);
        if(dinic.dinic(s, t) == tot)
            ans.emplace_back(x);
    }
    if(ans.empty()) cout << -1 << endl;
    else
    {
        cout << ans[0];
        for(int i = 1; i < (int)ans.size(); i++)
            cout << " " << ans[i];
        cout << endl;
    }
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
