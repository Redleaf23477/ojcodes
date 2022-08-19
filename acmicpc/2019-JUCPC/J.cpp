#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
const LL MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    LL n, k, m; cin >> n >> k >> m;

    LL ans = 0;

    LL NN = min(k, m / 2);
    vector<vector<LL>> dp(m+1, vector<LL>(NN+1, 0));  // dp[step][vertex]
    dp[0][0] = 1;
    for (int step = 1; step <= m; step++) {
        for (int u = 0; u <= NN; u++) {
            if (u != 0) dp[step][u] += dp[step-1][u-1];
            if (u != NN) dp[step][u] += dp[step-1][u+1];
            dp[step][u] %= MOD;
            
        }
        ans = (ans + dp[step][0]) % MOD;
//        cerr << "step = " << step << ", " << dp[step][0] << endl;
    }

    cout << ans * n * 2 % MOD << "\n";

}

