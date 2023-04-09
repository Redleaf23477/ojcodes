#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL MOD = 998244353;

LL fastpw(LL a, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = a * ans % MOD;
        p /= 2;
        a = a * a % MOD;
    }
    return ans;
}

LL modinv(LL x) { return fastpw(x, MOD-2); }

LL fac(LL x) {
    LL ans = 1;
    for (int i = 1; i <= x; i++) {
        ans = ans * i % MOD;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    LL tri_cnt = 1;
    for (int i = 0; i < n; i += 3) {
        vector<LL> w(3);
        cin >> w[0] >> w[1] >> w[2];
        sort(w.begin(), w.end());
        if (w[0] == w[2]) {
            tri_cnt = tri_cnt * 3 % MOD;
        } else if (w[0] == w[1]) {
            tri_cnt = tri_cnt * 2 % MOD;
        }
    }

    LL n_fac = fac(n/3);
    LL n_div_2_fac_inv = modinv(fac(n/6));

    cout << tri_cnt * n_fac % MOD * n_div_2_fac_inv % MOD * n_div_2_fac_inv % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



