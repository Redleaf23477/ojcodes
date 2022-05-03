#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return ans;
}

LL add(LL lhs, LL rhs) { return (lhs + rhs) % MOD; }
LL mul(LL lhs, LL rhs) { return lhs * rhs % MOD; }

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    LL modinv_2 = fastpw(2, MOD-2);
    // assert(2 * modinv_2 % MOD == 1);

    LL n; cin >> n;
    LL ans = 0;
    for (LL x = 1; x <= n; x++) {
        LL d = n / x;
        LL y = n / d;
        // cerr << "[" << x << "," << y << "] -> " << d << " --> " << d * (x + y) * (y - x + 1) / 2 << endl;
        // numbers in [x, y] occurs d times
        ans = add(ans, mul(d, mul(add(x, y), mul(add(y, 1 - x + MOD), modinv_2))));
        x = y;
    }
    cout << ans << "\n";
}