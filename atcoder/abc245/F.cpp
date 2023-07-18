#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);  // transpose
    vector<int> indeg(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[v].emplace_back(u);
        indeg[u]++;
    }
    int ans = n;
    queue<int> Q;
    for (int u = 0; u < n; u++) {
        if (indeg[u] == 0) Q.emplace(u);
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        ans--;
        for (auto v : graph[u]) {
            if (--indeg[v] == 0) {
                Q.emplace(v);
            }
        }
    }
    cout << ans << "\n";
}

/*
struct Kosaraju {
    vector<vector<int>> const &graph, &transp_graph;
    vector<int> scc_idx, scc_size;
    Kosaraju(vector<vector<int>> &G, vector<vector<int>> &transpG) : graph(G), transp_graph(transpG), scc_idx(G.size()) {
        kosaraju();
    }
    vector<bool> vis;
    vector<int> out_order;
    void dfs1(int u) {
        vis[u] = true;
        for (auto v : graph[u]) {
            if (!vis[v]) dfs1(v);
        }
        out_order.emplace_back(u);
    }
    void dfs2(int u, int idx) {
        vis[u] = true;
        scc_idx[u] = idx;
        scc_size.back() += 1;
        for (auto v : transp_graph[u]) {
            if (!vis[v]) {
                dfs2(v, idx);
            }
        }
    }
    void kosaraju() {
        vis.assign(graph.size(), false);
        for (int u = 0; u < (int)graph.size(); u++) {
            if (!vis[u]) {
                dfs1(u);
            }
        }
        vis.assign(graph.size(), false);
        for (; !out_order.empty(); out_order.pop_back()) {
            if (vis[out_order.back()]) continue;
            int idx = scc_size.size();
            scc_size.emplace_back(0);
            dfs2(out_order.back(), idx);
        }
    }
    vector<int> &get_scc_idx() { return scc_idx; }
    vector<int> &get_scc_size() { return scc_size; }
};

void dfs(int u, vector<bool> &vis, vector<vector<int>> const &graph) {
    vis[u] = true;
    for (auto v : graph[u]) {
        if (!vis[v]) dfs(v, vis, graph);
    }
}

void solve_with_kosaraju() {
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<vector<int>> transp_graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        transp_graph[v].emplace_back(u);
    }

    Kosaraju scc(graph, transp_graph);
    auto &scc_idx = scc.get_scc_idx();
    auto &scc_size = scc.get_scc_size();

    vector<bool> vis(n, false);
    for (int u = 0; u < n; u++) {
        if (scc_size[scc_idx[u]] != 1 && !vis[u]) {
            dfs(u, vis, transp_graph);
        }
    }
    cout << accumulate(vis.begin(), vis.end(), 0) << "\n";
}
*/

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



