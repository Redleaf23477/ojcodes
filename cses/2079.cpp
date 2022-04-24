#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<int> size(n, 1);
    int ans = -1;
    function<void(int,int)> dfs = [&](int u, int pa) {
        int max_subtree_size = 0;
        for (auto v : graph[u]) if (v != pa) {
            dfs(v, u);
            max_subtree_size = max(max_subtree_size, size[v]);
            size[u] += size[v];
        }
        if (pa != u) {
            int pa_sz = n - size[u];
            max_subtree_size = max(max_subtree_size, pa_sz);
        }
        if (max_subtree_size <= n/2) {
            ans = u;
        }
    };
    dfs(0, 0);
    cout << ans + 1 << "\n";
}

