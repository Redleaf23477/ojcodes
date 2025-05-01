#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int MAX = 500;
constexpr LL MOD = 998244353;

LL dp[MAX][MAX][MAX][MAX];

void solve() {
    int n, m; cin >> n >> m;

    // dp[i][k][l] = when I finish n=i, I have k from n=1 in total, now l left from n=1


    // n = 1
    // init: (0, 0) must give me
    dp[0][1][1] = 1;
    for (int j = 1; j < m; j++) {
        for (int k = 0; k < m; k++) {
            for (int l = 0; l <= k; l++) {
                LL add = 0;
                // give me
                if (k > 0 && l > 0) {
                    add += dp[0][k - 1][l - 1];
                }

                // give him
                if (l + 1 <= k) {
                    add += dp[0][k][l + 1];
                }

                // dp[0][j] <- dp[0][j-1]
                dp[0][k][l] = (dp[0][k][l] + add) % MOD;
            }
        }
    }

    // n > 1
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < m; k++) {
            for (int l = 0; l <= k; l++) {
                dp[0][k][l] = ...;
            }
        }
    }

    // ans = ???
    LL ans = 0;

    ans %= MOD;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

