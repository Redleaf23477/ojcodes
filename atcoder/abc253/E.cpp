#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

void solve() {
    LL N, M, K; cin >> N >> M >> K;
    vector<vector<LL>> dp(N, vector<LL>(M + 1, 0));
    for (int j = 1; j <= M; j++) {
        dp[0][j] = dp[0][j - 1] + 1;
    }
    // dp[i][j] = sum(dp[i-1][1], ..., dp[i-1][j - K]) + sum(dp[i-1][j+K], ..., dp[i-1][M])
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= M; j++) {
            if (K == 0) {
                dp[i][j] += dp[i - 1][M];
            } else {
                if (j - K > 0) dp[i][j] += dp[i - 1][j - K] - dp[i - 1][0] + MOD;
                if (j + K <= M) dp[i][j] += dp[i - 1][M] - dp[i - 1][j + K - 1] + MOD;
            }
        }
        for (int j = 1; j <= M; j++) {
            dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[N - 1][M] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}

