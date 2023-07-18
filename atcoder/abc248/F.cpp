#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    LL MOD; cin >> MOD;
    // dp[first i columns][delete j edges][connected?]
    vector<vector<vector<LL>>> dp(N, vector<vector<LL>>(N, vector<LL>(2, 0)));
    dp[0][0][true] = 1;
    dp[0][1][false] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // no missing
            dp[i][j][true] = (dp[i][j][true] + dp[i-1][j][true] + dp[i-1][j][false]) % MOD;
            // delete one
            if (j >= 1) {
                // delete up or down
                dp[i][j][true] = (dp[i][j][true] + 2 * dp[i-1][j-1][true]) % MOD;
                // detele vertical
                dp[i][j][true] = (dp[i][j][true] + dp[i-1][j-1][true]) % MOD;
                dp[i][j][false] = (dp[i][j][false] + dp[i-1][j-1][false]) % MOD;
            }
            // delete two
            if (j >= 2) {
                // delete up or down
                dp[i][j][false] = (dp[i][j][false] + 2 * dp[i-1][j-2][true]) % MOD;
            }
        }
    }
    for (int i = 1; i < N; i++) {
        cout << dp[N-1][i][true] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



