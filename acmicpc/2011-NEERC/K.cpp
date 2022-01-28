#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL N = 1428;
constexpr LL LG_N = 24;
constexpr LL MOD = 1e9;

LL dp[N][LG_N];

int main() {
    ios::sync_with_stdio(false); cin.tie();
    // init
    dp[1][1] = 1, dp[0][0] = 1;
    for (int i = 2; i < N; i++) for (int j = 1; j < LG_N; j++) {
        for (int k = 0; k < i; k++) {
            if (j >= 1) dp[i][j] = (dp[i][j] + dp[k][j-1] * dp[i-k-1][j-1]) % MOD;
            if (j >= 2) dp[i][j] = (dp[i][j] + dp[k][j-1] * dp[i-k-1][j-2]) % MOD;
            if (j >= 2) dp[i][j] = (dp[i][j] + dp[k][j-2] * dp[i-k-1][j-1]) % MOD;
        }
    }


    int n;
    while (cin >> n) {
        LL ans = 0;
        for (int h = 0; h < LG_N; h++) ans = (ans + dp[n][h]) % MOD;
        cout << setw(9) << setfill('0') << ans << "\n";
    }
}

