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

int n;
vector<vector<string>> arr;
max_flow dinic;

void init()
{
    cin >> n;
    arr.assign(n, vector<string>(26));
    for(int i = 0; i < n; i++)
    {
        int k; cin >> k;
        while(k--)
        {
            string tmp; cin >> tmp;
            for(auto &x : tmp) x = tolower(x); tmp[0] = toupper(tmp[0]);
            arr[i][tmp[0]-'A'] = tmp;
        }
    }
    // build flow graph
    // 0 : s
    // 1 : t
    // 2+i : i-th problem
    // 2+n+i : i-th order
    int s = 0, t = 1;
    dinic = max_flow(2+n+n);
    for(int i = 0; i < n; i++)
    {
        dinic.add_edge(s, 2+i, 1);
        for(int j = 0; j < n; j++)
        {
            if(arr[i][j].size() != 0)
                dinic.add_edge(2+i, 2+n+j, 1);
        }
    }
    for(int i = 0; i < n; i++)
        dinic.add_edge(2+n+i, t, 1);
}

void process()
{
    dinic.dinic(0, 1);
    vector<string> prob(n);
    for(int i = 0; i < n; i++)
    {
        int u = 2+i;
        for(auto x : dinic.AL[u])
        {
            auto [v, cap, f] = dinic.EL[x];
            if(f == 1) prob[v-2-n] = arr[i][v-2-n];
        }
    }
    for(auto p : prob) cout << p << endl;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T, caseN = 0; cin >> T;
    while(T--)
    {
        cout << "Case #" << ++caseN << ":" << endl;
        init();
        process();
    }
    cout.flush();
}
