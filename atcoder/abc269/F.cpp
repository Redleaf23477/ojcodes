#include <bits/stdc++.h>
using namespace std;
using LL = long long;
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

const LL modinv2 = fastpw(2, MOD - 2);

LL calc(LL u, LL d, LL l, LL r, LL C, bool even) {
    u = (u % 2 != even? u + 1 : u);
    d = (d % 2 != even? d - 1 : d);
    l = (l % 2 != even? l + 1 : l);
    r = (r % 2 != even? r - 1 : r);

    LL row_len = ((r - l) / 2 + 1) % MOD;
    LL row_delta = (2 * C * row_len) % MOD;
    LL col_len = ((d - u) / 2 + 1) % MOD;

    LL row = (((u * C + l + 1) + (u * C + r + 1))) % MOD * row_len % MOD * modinv2 % MOD;
    LL sum = (row + row + row_delta * (col_len - 1)) % MOD * col_len % MOD * modinv2 % MOD;

    return sum;
}

void solve() {
    LL R, C; cin >> R >> C;
    int Q; cin >> Q;
    while (Q--) {
        int u, d, l, r; cin >> u >> d >> l >> r;
        u--, d--, l--, r--;
        LL ans = 0;
        // even even
        ans = (ans + calc(u, d, l, r, C, true)) % MOD;
        // odd odd
        ans = (ans + calc(u, d, l, r, C, false)) % MOD;
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}

