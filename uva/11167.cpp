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
  vector<edge> EL;
  vector<vi> AL;

  max_flow(int initialV = 0) : V(initialV) {
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
int n, m;
ll sum;
max_flow dinic;

void init()
{
    sum = 0;
    cin >> m;
    // 0 ~ 50000: time
    // 50000 + i: i-th monkey
    // 50000 + n + 1: s
    // 50000 + n + 2: t
    s = 50000 + n + 1, t = s + 1;
    dinic = max_flow(50000+n+3);
    for(int i = 1; i <= n; i++)
    {
        int v, l, r; cin >> v >> l >> r;
        sum += v;
        int monkey = 50000 + i;
        dinic.add_edge(s, monkey, v);
        for(int x = l; x < r; x++)
            dinic.add_edge(monkey, x, 1);
    }
    for(int i = 0; i <= 50000; i++)
        dinic.add_edge(i, t, m);
}

void process()
{
    ll mf = dinic.dinic(s, t);
    if(mf != sum) { cout << "No" << endl; return; }
    cout << "Yes" << endl;
    vector<set<int>> monkey(n);
    for(int i = 50000 + 1; i <= 50000 + n; i++)
    {
        for(auto u : dinic.AL[i])
        {
            auto [v, _, f] = dinic.EL[u];
            if(f == 1) monkey[i-50001].insert(v);
        }
    }
    for(auto s : monkey)
    {
        vector<tuple<int,int>> ans;
        int l = -1, r = -1;
        for(auto x : s)
        {
            if(l == -1) l = x, r = x+1;
            else if(x == r) r = x+1;
            else ans.emplace_back(l, r), l = x, r = x+1;
        }
        ans.emplace_back(l, r);
        cout << ans.size();
        for(auto [l,r] : ans) cout << " (" << l << "," << r << ")";
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 0;
    while(cin >> n && n)
    {
        cout << "Case " << ++T << ": ";
        init();
        process();
    }
    cout.flush();
}

