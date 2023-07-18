#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void dfs_tree(vector<vector<int>> const &graph, int n) {
    vector<bool> vis(n, false);
    vector<pair<int,int>> tree;
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v : graph[u]) {
            if (vis[v]) continue;
            tree.emplace_back(u, v);
            dfs(v);
        }
    };
    dfs(0);
    for (auto [u, v] : tree) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

void bfs_tree(vector<vector<int>> const &graph, int n) {
    vector<bool> vis(n, false);
    vector<pair<int,int>> tree;
    queue<int> Q;
    Q.emplace(0), vis[0] = true;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto v : graph[u]) {
            if (vis[v]) continue;
            tree.emplace_back(u, v);
            Q.emplace(v), vis[v] = true;
        }
    }
    for (auto [u, v] : tree) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    dfs_tree(graph, n);
    bfs_tree(graph, n);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



