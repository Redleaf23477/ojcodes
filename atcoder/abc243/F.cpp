#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;
constexpr int K = 50;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p /= 2;
    }
    return ans;
}

vector<LL> fac(K+1, 1), fac_inv(K+1, 1);
void calc_fac() {
    for (int i = 1; i <= K; i++) {
        fac[i] = fac[i-1] * i % MOD;
    }
    fac_inv[K] = fastpw(fac[K], MOD-2);
    for (int i = K-1; i >= 0; i--) {
        fac_inv[i] = fac_inv[i + 1] * (i + 1) % MOD;
    }
}

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<LL> W(n);
    for (auto &x : W) cin >> x;
    LL wsum = accumulate(W.begin(), W.end(), 0ll) % MOD;

    // dp[consider first i elem][I pick j kinds][I pick k elem] = prod(wi^ci / ci!)
    vector dp(n+1, vector<vector<LL>>(m+1, vector<LL>(k+1, 0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        LL w = W[i-1];
        // I pick i-th elem
        for (int kinds = 1; kinds <= m; kinds++) {
            for (int cnt = 1; cnt <= k; cnt++) {
                for (int pick = 1; pick <= cnt; pick++) {
                    LL new_prob = dp[i-1][kinds-1][cnt-pick] * fastpw(w, pick) % MOD * fac_inv[pick] % MOD;
                    dp[i][kinds][cnt] = (dp[i][kinds][cnt] + new_prob) % MOD;
                }
            }
        }
        // I don't pick i-th elem
        for (int kinds = 0; kinds <= m; kinds++) {
            for (int cnt = 0; cnt <= k; cnt++) {
                dp[i][kinds][cnt] = (dp[i][kinds][cnt] + dp[i-1][kinds][cnt] * 1) % MOD;
            }
        }
    }

    cout << fac[k] * fastpw(fastpw(wsum, k), MOD-2) % MOD * dp[n][m][k] % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    calc_fac();
    int T = 1;
    while (T--) {
        solve();
    }
}



