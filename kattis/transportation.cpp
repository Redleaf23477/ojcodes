// Disclaimer: This code is a hybrid between old CP1-2-3 implementation of
// Edmonds Karp's algorithm -- re-written in OOP fashion and the fast
// Dinic's algorithm implementation by
// https://github.com/jaehyunp/stanfordacm/blob/master/code/Dinic.cc
// This code is written in modern C++17 standard
// Cherry-picked from cp3

#include <bits/stdc++.h>
#define endl '\n'
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
int state, raw, fac, trans;
max_flow dinic;

void init()
{
    cin >> state >> raw >> fac >> trans;
    int idx = 0;
    map<string, int> mp;
    vector<int> r, f;
    for(int i = 0; i < raw; i++)
    {
        string str; cin >> str;
        if(mp.count(str) == 0) mp[str] = idx++;
        r.emplace_back(mp[str]);
    }
    for(int i = 0; i < fac; i++)
    {
        string str; cin >> str;
        if(mp.count(str) == 0) mp[str] = idx++;
        f.emplace_back(mp[str]);
    }
    // 0 - (state-1) : state
    // state - (state+trans-1) : trans 1
    // state+trans + (state+2*trans-1) : trans2
    // state+2*trans, +1 : s, t
    s = state+2*trans, t = s+1;
    dinic = max_flow(t+1);
    for(auto i : r) dinic.add_edge(s, i, 1);
    for(auto i : f) dinic.add_edge(i, t, 1);
    for(int i = 0; i < trans; i++)
    {
        int k; cin >> k;
        while(k--)
        {
            string str; cin >> str;
            if(mp.count(str) == 0) mp[str] = idx++;
            int x = mp[str];
            dinic.add_edge(x, state+i, 1);
            dinic.add_edge(state+trans+i, x, 1);
        }
        dinic.add_edge(state+i, state+trans+i, 1);
    }
}

void process()
{
    cout << dinic.dinic(s, t) << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    process();
    cout.flush();
}
