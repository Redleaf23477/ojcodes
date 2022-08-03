#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    constexpr LL INF = 1e15;
    int n; cin >> n;
    vector<LL> arr(n + 1, 0);
    vector<vector<int>> graph(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        int pa; cin >> pa;
        graph[pa].emplace_back(i);
    }

    vector<LL> dp(n+1, INF);
    function<LL(int)> dfs = [&](int u) {
        LL ans = 0;
        for (auto v : graph[u]) {
            ans += dfs(v);
            dp[u] = min(dp[u], dp[v]);
        }
        bool covered = false;
        for (auto v : graph[u]) {
            if (dp[u] == dp[v] && !covered) {
                covered = true;
            } else {
                ans += dp[v];
            }
        }
        if (dp[u] == INF || arr[u] > dp[u]) dp[u] = arr[u];
        return ans;
    };

    cout << dfs(0) + dp[0] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

