#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;
constexpr LL N = 5000;

vector<LL> fac(N+1, 1), fac_inv(N+1, 1);

LL fastpw(LL a, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        p /= 2;
    }
    return ans;
}

void calc_fac() {
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i-1] * i % MOD;
    }
    fac_inv[N] = fastpw(fac[N], MOD - 2);
    for (int i = N-1; i >= 0; i--) {
        fac_inv[i] = fac_inv[i+1] * (i + 1) % MOD;
    }
}

LL put(LL len, LL used) {
    // place (used) char into (len+1) positions
    // a_1 + a_2 + ... a_{len+1} = used, a_i >= 0
    // (used + len, used)
    return fac[used + len] * fac_inv[used] % MOD * fac_inv[len] % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    calc_fac();

    string str; cin >> str;
    int n = str.size();
    vector<int> cnt(27);
    for (auto ch : str) cnt[ch - 'a' + 1] += 1;
    
    // dp[char_kind][used_num]
    vector<vector<LL>> dp(26+1, vector<LL>(n+1, 0));
    dp[0][0] = 1;
    for (int ch = 1; ch <= 26; ch++) {
        dp[ch][0] = 1;
        for (int len = 1; len <= n; len++) {
            for (int used = 0; used <= min(len, cnt[ch]); used++) {
                dp[ch][len] += dp[ch - 1][len - used] * put(len - used, used) % MOD;
            }
            dp[ch][len] %= MOD;
        }
    }
    LL ans = accumulate(dp[26].begin() + 1, dp[26].end(), 0ll) % MOD;
    cout << ans << "\n";
}

