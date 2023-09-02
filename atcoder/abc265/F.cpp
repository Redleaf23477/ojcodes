#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

void solve() {
    int N, D; cin >> N >> D;
    vector<int> P(N), Q(N);
    for (auto &x : P) cin >> x;
    for (auto &x : Q) cin >> x;
    for (int i = 0; i < N; i++) {
        if (P[i] > Q[i]) swap(P[i], Q[i]);
    }

    // dp[prefix][dist acc 1][dist acc 2]
    vector dp(2, vector<vector<LL>>(D + 1, vector<LL>(D + 1, 0)));
    vector<vector<LL>> dp_acc1, dp_acc2, dp_acc3;  // (D+1) * (D+1)

    auto run_dp_acc = [&](vector<vector<LL>> const &dp_prv) {
        dp_acc1 = dp_acc2 = dp_acc3 = dp_prv;

        for (int x = 1; x <= D; x++) {
            for (int y = 1; y <= D; y++) {
                dp_acc1[x][y] = (dp_acc1[x][y] + dp_acc1[x - 1][y - 1]) % MOD;
            }
        }
        for (int x = D - 1; x >= 0; x--) {
            for (int y = 1; y <= D; y++) {
                dp_acc2[x][y] = (dp_acc2[x][y] + dp_acc2[x + 1][y - 1]) % MOD;
            }
        }
        for (int x = D - 1; x >= 0; x--) {
            for (int y = D - 1; y >= 0; y--) {
                dp_acc3[x][y] = (dp_acc3[x][y] + dp_acc3[x + 1][y + 1]) % MOD;
            }
        }


    };
    auto get_val = [D](vector<vector<LL>> const &dp_acc, int x, int y) {
        if (0 <= x && x <= D && 0 <= y && y <= D) {
            return dp_acc[x][y];
        } else {
            return 0ll;
        }
    };

    dp[0][0][0] = 1;
    for (int i = 1; i <= N; i++) {
        auto &dp_now = dp[i % 2];
        auto &dp_prv = dp[1 - i % 2];
        int p = P[i - 1], q = Q[i - 1];
        for (auto &row : dp_now) {
            fill(row.begin(), row.end(), 0);
        }

        run_dp_acc(dp_prv);

        // calculate dp_now
        for (int x = 0; x <= D; x++) {
            for (int y = 0; y <= D; y++) {
                // range: max(p-x, q-y) to min(p+x, q+y)
                int L = max(p - x, q - y);
                int R = min(p + x, q + y);
                // - range 1: [max(p-x, q-y) , p)
                if (p - 1 >= L) {
                    dp_now[x][y] += get_val(dp_acc1, x - p + p - 1, y - q + p - 1);
                    dp_now[x][y] += MOD - get_val(dp_acc1, x - p + L - 1, y - q + L - 1);
                }
                // - range 2: [p , q]
                dp_now[x][y] += get_val(dp_acc2, x + p - min(R, q), y - q + min(R, q));
                dp_now[x][y] += MOD - get_val(dp_acc2, x + p - max(L, p) + 1, y - q + max(L, p) - 1);
                // - range 3: (q , min(p+x, q+y)]
                if (q + 1 <= R) {
                    dp_now[x][y] += get_val(dp_acc3, x + p - R, y + q - R);
                    dp_now[x][y] += MOD - get_val(dp_acc3, x + p - q, y + q - q);
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



