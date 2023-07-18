#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL MOD = 998244353;

void solve() {
    int N, M, K, S, T, X; cin >> N >> M >> K >> S >> T >> X; S--, T--, X--;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    // dp[len of path][stop at vertex u][parity of X]
    vector dp(K + 1, vector<vector<LL>>(N, vector<LL>(2, 0)));
    dp[0][S][0] = 1;
    for (int len = 1; len <= K; len++) {
        for (int u = 0; u < N; u++) {
            for (int parity : {0, 1}) {
                for (int v : graph[u]) {
                    int p2 = (v == X? 1 - parity : parity);
                    dp[len][u][parity] = (dp[len][u][parity] + dp[len - 1][v][p2]) % MOD;
                }
            }
        }
    }

    cout << dp[K][T][0] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



