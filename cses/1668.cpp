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
    vector<int> color(n, -1);
    function<bool(int)> dfs = [&](int u) {
        for (auto v : graph[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                if (!dfs(v)) return false;
            } else if (color[v] == color[u]) {
                return false;
            }
        }
        return true;
    };
    bool ans = true;
    for (int i = 0; i < n && ans; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            ans = dfs(i);
        }
    }
    if (ans) {
        for (auto x : color) cout << x + 1 << " ";
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

