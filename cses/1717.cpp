#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    constexpr int N = 2'000'000;
    vector<LL> factorial(N+1, 1);
    for (int i = 2; i <= N; i++) factorial[i] = factorial[i-1] * i % MOD;
    vector<LL> fac_inv(N+1, 1);
    vector<LL> inv(N+1, 1);
    fac_inv[N] = fastpw(factorial[N], MOD-2);
    for (LL i = N-1, suff = N; i >= 2; suff = suff * i % MOD, i--) {
        inv[i] = factorial[i-1] * suff % MOD * fac_inv[N] % MOD;
    }
    fac_inv[0] = inv[0];
    for (int i = 1; i < N; i++) fac_inv[i] = fac_inv[i-1] * inv[i] % MOD;

    int n; cin >> n;
    LL ans = 0;
    for (int i = 0, sign = 1; i <= n; i++, sign *= -1) {
        ans = (ans + sign * fac_inv[i] % MOD + MOD) % MOD;
    }
    cout << factorial[n] * ans % MOD << "\n";

}