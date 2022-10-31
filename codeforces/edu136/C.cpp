#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

const LL MOD = 998244353;
vector<LL> fac, fac_inv;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p /= 2;
    }
    return ans;
}

LL C(int n, int m) {
    return fac[n] * fac_inv[m] % MOD * fac_inv[n - m] % MOD;
}

LL f(int n) {
    // Tie
    if (n == 0) return 0;

    // I have the largest number
    LL ans = C(n - 1, n / 2 - 1);
    // I don't have the largest number
    // But I have the second largest number
    ans = (ans + C(n - 2, n / 2 - 1) - f(n-2) - 1 + MOD) % MOD;
    return ans;
}

void solve() {
    LL n; cin >> n;
    LL A = f(n);
    LL B = (C(n, n/2) - A - 1 + MOD + MOD) % MOD;
    LL D = 1;
    cout << A << " " << B << " " << D << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    const int N = 60;
    fac.assign(N+1, 1);
    for (int i = 2; i <= N; i++) {
        fac[i] = i * fac[i-1] % MOD;
    }
    fac_inv = fac;
    fac_inv[N] = fastpw(fac[N], MOD - 2);
    for (LL i = N-1, suff = N; i > 0; suff = suff * i % MOD, i--) {
        fac_inv[i] = fac_inv[N] * suff % MOD;
    }

    int T; cin >> T;
    while (T--) {
        solve();
    }
}

