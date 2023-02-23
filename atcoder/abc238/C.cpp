#include <bits/stdc++.h>
using namespace std;
using LL = __int128;
constexpr LL MOD = 998244353;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL modinv2 = fastpw(2, MOD - 2);
    long long int _N; cin >> _N;
    LL N = _N;
    LL ans = 0;
    for (LL base = 1; base <= N; base *= 10) {
        LL L = base, R = min(N, 10 * base - 1);
        LL num = (R - L + 1);
        L %= MOD, R %= MOD, num %= MOD;
        LL add = (L + R) * num % MOD * modinv2 % MOD + MOD - num * base % MOD + num;
        ans = (ans + add) % MOD;
    }
    cout << (long long int) ans << "\n";
}

