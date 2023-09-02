#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

void solve() {
    int N, D; cin >> N >> D;
    vector<int> P(N), Q(N);
    for (auto &x : P) cin >> x;
    for (auto &x : Q) cin >> x;

    // dp[prefix][dist acc 1][dist acc 2]
    vector dp(2, vector<vector<LL>>(D + 1, vector<LL>(D + 1, 0)));

    dp[0][0][0] = 1;
    for (int i = 1; i <= N; i++) {
        auto &dp_now = dp[i % 2];
        auto &dp_prv = dp[1 - i % 2];
        int p = P[i - 1], q = Q[i - 1];
        for (auto &row : dp_now) {
            fill(row.begin(), row.end(), 0);
        }

        // calculate dp_now
        for (int x = 0; x <= D; x++) {
            for (int y = 0; y <= D; y++) {
                // range: max(p-x, q-y) to min(p+x, q+y)
                for (int pt = max(p - x, q - y); pt <= min(p + x, q + y); pt++) {
                    int dx = abs(pt - p), dy = abs(pt - q);
                    dp_now[x][y] += dp_prv[x - dx][y - dy];
                }
                dp_now[x][y] %= MOD;
            }
        }
    }

    LL ans = 0;
    for (int x = 0; x <= D; x++) {
        for (int y = 0; y <= D; y++) {
            ans += dp[N % 2][x][y];
        }
    }
    cout << ans % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



