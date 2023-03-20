#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr int NUM = 1e6;
vector<bool> is_prime(NUM+1, true);

void build_prime_table() {
    is_prime[0] = is_prime[1] = false;
    for (LL i = 2; i <= NUM; i++) {
        if (!is_prime[i]) continue;
        for (LL j = i * i; j <= NUM; j += i) {
            is_prime[j] = false;
        }
    }
}

constexpr LL MOD = 998244353;
vector<LL> fac(NUM+1, 1), fac_inv(NUM+1, 1);

LL fastpw(LL a, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        p /= 2;
    }
    return ans;
}

LL modinv(LL a, LL p) { return fastpw(a, p-2); }

void build_fac_table() {
    for (LL i = 1; i <= NUM; i++) {
        fac[i] = fac[i-1] * i % MOD;
    }
    fac_inv[NUM] = modinv(fac[NUM], MOD);
    for (LL i = NUM-1; i > 0; i--) {
        fac_inv[i] = fac_inv[i+1] * (i+1) % MOD;
    }

    for (int i = NUM; i >= 0; i--) {
        assert(fac[i] * fac_inv[i] % MOD == 1);
    }
}

void solve() {
    int n; cin >> n;
    map<int,int> data;
    for (int i = 0; i < 2*n; i++) {
        int x; cin >> x; 
        data[x]++;
    }
    int m = data.size(); 
    vector<pair<int,int>> arr(data.begin(), data.end());

    // dp[prefix][num_fac_used]
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        auto [num, cnt] = arr[i-1];
        if (is_prime[num]) {
            // 1) one put down, remain put up
            for (int j = 1; j <= n; j++) {
                // cerr << "dp[" << i << "][" << j << "] <- dp[" << i-1 << "][" << j-1 << "] * fac_inv(" << cnt-1 << ")" << endl;
                dp[i][j] = (dp[i][j] + dp[i-1][j-1] * fac_inv[cnt-1] % MOD) % MOD;
            }
            // 2) all put up
            for (int j = 0; j <= n; j++) {
                // cerr << "dp[" << i << "][" << j << "] <- dp[" << i-1 << "][" << j << "] * fac_inv(" << cnt << ")" << endl;
                dp[i][j] = (dp[i][j] + dp[i-1][j] * fac_inv[cnt] % MOD) % MOD;
            }
        } else {
            // 1) all put up
            for (int j = 0; j <= n; j++) {
                // cerr << "dp[" << i << "][" << j << "] <- dp[" << i-1 << "][" << j << "] * fac_inv(" << cnt << ")" << endl;
                dp[i][j] = (dp[i][j] + dp[i-1][j] * fac_inv[cnt] % MOD) % MOD;
            }
        }
    }
    cout << dp[m][n] * fac[n] % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    build_prime_table();
    build_fac_table();
    int T = 1;
    while (T--) {
        solve();
    }
}



