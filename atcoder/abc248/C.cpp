#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

void solve() {
    int N, M, K; cin >> N >> M >> K;
    vector<vector<LL>> dp(N + 1, vector<LL>(K + 1, 0));
    fill(dp[0].begin(), dp[0].end(), 1);
    for (int i = 1; i <= N; i++) {
        for (int k = 1; k <= K; k++) {
            // dp[i][k] = dp[i-1][k-1] + ... + dp[i-1][k-M]
            dp[i][k] = dp[i - 1][k - 1];
            if (k - M > 0) dp[i][k] = (dp[i][k] - dp[i - 1][k - M - 1] + MOD) % MOD;
        }
        for (int k = 1; k <= K; k++) {
            dp[i][k] = (dp[i][k] + dp[i][k - 1]) % MOD;
        }
    }

    cout << dp[N][K] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



