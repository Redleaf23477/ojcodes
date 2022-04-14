#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> graph(n);
    vector<int> indeg(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        indeg[u]++, indeg[v]++;
    }
    vector<LL> ans(n, 0), sz(n, 0), dist(n, 0);
    function<void(int,int)> dfs1 = [&](int u, int pa) {
        sz[u] = 1;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            dfs1(v, u);
            sz[u] += sz[v];
            dist[u] += dist[v] + sz[v];
        }
    };
    function<void(int,int)> dfs2 = [&](int u, int pa) {
        for (auto v : graph[u]) {
            ans[u] += dist[v] + sz[v];
        }
        for (auto v : graph[u]) {
            if (v == pa) continue;
            dist[u] = ans[u] - dist[v] - sz[v];
            sz[u] = n - sz[v];
            dfs2(v, u);
        }
    };
    dfs1(0, 0);
    dfs2(0, 0);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}