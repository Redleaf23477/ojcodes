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
    }
    vector<bool> vis(n, false);
    vector<int> stk, instk(n, -1);
    function<bool(int)> dfs = [&](int u) {
        vis[u] = true;
        instk[u] = stk.size();
        stk.emplace_back(u);
        for (auto v : graph[u]) {
            if (instk[v] != -1) {
                cout << stk.size() - instk[v] + 1 << "\n";
                for (size_t i = instk[v]; i < stk.size(); i++) {
                    cout << stk[i] + 1 << " ";
                }
                cout << v + 1 << "\n";
                return true;
            } else if (!vis[v]) {
                if (dfs(v)) return true;
            }
        }
        instk[u] = -1;
        stk.pop_back();
        return false;
    };
    bool ans = false;
    for (int i = 0; i < n && !ans; i++) {
        if (!vis[i]) {
            ans = dfs(i);
        }
    }
    if (!ans) {
        cout << "IMPOSSIBLE\n";
    }
}