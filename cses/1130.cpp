#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<vector<int>> dp(n, vector<int>(2, 0));
    function<void(int,int)> dfs = [&](int u, int pa) {
        for (auto v : graph[u]) {
            if (v == pa) continue;
            dfs(v, u);
            dp[u][0] += max(dp[v][0], dp[v][1]);
        }
        for (auto v : graph[u]) {
            if (v == pa) continue;
            dp[u][1] = max(dp[u][1], dp[u][0] - max(dp[v][0], dp[v][1]) + dp[v][0] + 1);
        }
    };
    dfs(0, 0);
    cout << max(dp[0][0], dp[0][1]) << "\n";
}