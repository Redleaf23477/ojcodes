#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL MOD = 998244353;

void solve() {
    size_t N, K; cin >> N >> K;
    string S; cin >> S;
    size_t MASK = (1u << K) - 1;

    vector<vector<LL>> dp(N, vector<LL>(1u << K, 0));
    if (S[0] == 'A' || S[0] == '?') dp[0][0] += 1;
    if (S[0] == 'B' || S[0] == '?') dp[0][1] += 1;

    for (size_t i = 1; i < K - 1; i++) {
        for (size_t m = 0; m < (1u << i); m++) {
            if (S[i] == 'A' || S[i] == '?') {
                dp[i][(m << 1)] += dp[i - 1][m];
            }
            if (S[i] == 'B' || S[i] == '?') {
                dp[i][(m << 1) + 1] += dp[i - 1][m];
            }
        }
        // mod clean up
        for (size_t m = 0; m < (1u << (i + 1)); m++) {
            dp[i][m] %= MOD;
        }
    }

    auto good = [K, MASK](size_t m, size_t tail) {
        m = ((m << 1) + tail) & MASK;
        bool is_palin = true;
        for (size_t l = 0, r = K - 1; l < r; l++, r--) {
            size_t l_bit = (m >> l) & 1;
            size_t r_bit = (m >> r) & 1;
            if (l_bit != r_bit) is_palin = false;
        }
        return !is_palin;
    };
    for (size_t i = K - 1; i < N; i++) {
        for (size_t m = 0; m < (1u << K); m++) {
            if (S[i] == 'A') {
                if (good(m, 0)) {
                    dp[i][(m << 1) & MASK] += dp[i - 1][m];
                }
            } else if (S[i] == 'B') {
                if (good(m, 1)) {
                    dp[i][((m << 1) + 1) & MASK] += dp[i - 1][m];
                }
            } else {
                if (good(m, 0)) {
                    dp[i][(m << 1) & MASK] += dp[i - 1][m];
                }
                if (good(m, 1)) {
                    dp[i][((m << 1) + 1) & MASK] += dp[i - 1][m];
                }
            }
        }
        // mod clean up
        for (size_t m = 0; m < (1u << K); m++) {
            dp[i][m] %= MOD;
        }
    }

    LL ans = 0;
    for (size_t m = 0; m < (1u << K); m++) {
        ans += dp[N - 1][m];
    }
    cout << ans % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

