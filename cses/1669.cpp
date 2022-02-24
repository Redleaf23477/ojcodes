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
    vector<int> stk;
    function<bool(int,int)> dfs = [&](int u, int pa) {
        vis[u] = true;
        stk.emplace_back(u);
        for (auto v : graph[u]) {
            if (v == pa) continue;
            if (vis[v]) {
                auto i = find(stk.begin(), stk.end(), v) - stk.begin();
                cout << stk.size() - i + 1 << "\n";
                for (; i < stk.size(); i++) {
                    cout << stk[i] + 1 << " ";
                }
                cout << v + 1 << "\n";
                return true;
            } else {
                if (dfs(v, u)) return true;
            }
        }
        stk.pop_back();
        return false;
    };
    bool ans = false;
    for (int i = 0; i < n && !ans; i++) {
        if (!vis[i]) {
            ans = dfs(i, i);
        }
    }
    if (!ans) {
        cout << "IMPOSSIBLE\n";
    }
}

