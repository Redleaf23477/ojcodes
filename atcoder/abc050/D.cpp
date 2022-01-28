#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL fastpw(LL x, LL p, LL m) {
    LL ans = (x % m != 0);
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % m;
        x = x * x % m;
        p /= 2;
    }
    return ans;
}

LL modinv(LL n, LL m) {
    return fastpw(n, m-2, m);
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    constexpr LL MOD = 1e9 + 7;
    LL N; cin >> N;
    LL x = (1 + N / 2) % MOD;
    LL s = ((1 + x) % MOD * x % MOD - 1 + MOD) % MOD;
    if (N % 2 == 0) s = (s + MOD - x % MOD) % MOD;
    cout << s << endl;
}

