#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    int lgn = log2(n) + 1;
    vector<vector<int>> dp(lgn+1, vector<int>(n));
    vector<int> dep(n, 0);
    function<void(int,int,int)> dfs = [&](int u, int pa, int d) {
        dp[0][u] = pa;
        dep[u] = d;
        for (auto v : graph[u]) {
            if (v != pa) dfs(v, u, d + 1);
        }
    };
    dfs(0, 0, 0);  // assume rooted at 0
    for (int k = 1; k <= lgn; k++) for (int u = 0; u < n; u++) {
        dp[k][u] = dp[k-1][dp[k-1][u]];
    }

    auto jump = [&](int u, int step) {
        for (int i = 0; step > 0; i++, step >>= 1) {
            if (step & 1) u = dp[i][u];
        }
        return u;
    };
    auto lca = [&](int u, int v) {
        if (dep[u] > dep[v]) swap(u, v);
        v = jump(v, dep[v] - dep[u]);
        if (u == v) return u;
        for (int k = lgn; k >= 0; k--) {
            if (dp[k][u] != dp[k][v]) {
                u = dp[k][u], v = dp[k][v];
            }
        }
        return dp[0][u];
    };

    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        int p = lca(u, v);
        cout << dep[u] + dep[v] - 2 * dep[p] << "\n";
    }
}