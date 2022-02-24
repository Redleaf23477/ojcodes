#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<bool> vis(n, false);
    vector<int> tmp;
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v : graph[u]) {
            if (!vis[v]) dfs(v);
        }
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            tmp.emplace_back(i);
            dfs(i);
        }
    }
    cout << tmp.size() - 1 << "\n";
    for (size_t i = 1; i < tmp.size(); i++) {
        cout << tmp[i-1] + 1 << " " << tmp[i] + 1 << "\n";
    }
}

