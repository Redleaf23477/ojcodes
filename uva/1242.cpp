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

struct Bridge {
  vector<int> imo;
  set<pair<int, int>> bridges; // all bridges (u, v), u < v
  vector<vector<int>> bcc; // bcc[i] has all vertices that belong to the i'th bcc
  vector<int> at_bcc; // node i belongs to at_bcc[i]
  int bcc_ctr, n;

  Bridge(const vector<vector<int>> &g) : bcc_ctr(0) {
    n = g.size();
    imo.resize(n), bcc.resize(n), at_bcc.resize(n);
    vector<int> vis(n), dpt(n);
    function<void(int, int, int)> mark = [&](int u, int fa, int d) {
      vis[u] = true, dpt[u] = d;
      for (int v : g[u]) {
        if (v == fa) continue;
        if (vis[v]) {
          if (dpt[v] > dpt[u]) {
            ++imo[v], --imo[u];
          }
        } else mark(v, u, d + 1);
      }
    };
    for (int i = 0; i < n; ++i) if (not vis[i]) mark(i, -1, 0);
    vis.assign(g.size(), 0);
    function<int(int)> expand = [&](int u) {
      vis[u] = true;
      int s = imo[u];
      for (int v : g[u]) {
        if (vis[v]) continue;
        int e = expand(v);
        if (e == 0) bridges.emplace(min(u, v), max(u, v));
        s += e;
      }
      return s;
    };
    for (int i = 0; i < n; ++i) if (not vis[i]) expand(i);
    fill(at_bcc.begin(), at_bcc.end(), -1);
    for (int u = 0; u < n; ++u) {
      if (~at_bcc[u]) continue;
      queue<int> que;
      que.emplace(u);
      at_bcc[u] = bcc_ctr;
      bcc[bcc_ctr].push_back(u);
      while (que.size()) {
        int v = que.front(); que.pop();
        for (int w : g[v]) {
          if (~at_bcc[w] || bridges.count({min(v, w), max(v, w)})) continue;
          que.emplace(w);
          at_bcc[w] = bcc_ctr;
          bcc[bcc_ctr].push_back(w);
        }
      }
      ++bcc_ctr;
    }
  }
};

int vn, en;
vector<vector<int>> graph;

void init();
void process();

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int caseN = 0;
    while(cin >> vn >> en && vn)
    {
        cout << "Case " << ++caseN << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init()
{
    graph.assign(vn, vector<int>());
    for(int i = 0; i < en; i++)
    {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
}

void process()
{
    Bridge b(graph); auto &bridges = b.bridges;
    int s, t; cin >> s >> t; s--, t--;
    vector<bool> vis(vn, false);
    std::function<bool(int)> dfs = [&](int u)->bool {
        vis[u] = true;
        if(u == t) return true;
        bool found = false;
        for(auto v : graph[u]) {
            if(vis[v]) continue;
            if(bridges.count(make_pair(min(u, v), max(u, v))) != 0) continue;
            if(found = dfs(v)) break;
        }
        return found;
    };
    if(dfs(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

