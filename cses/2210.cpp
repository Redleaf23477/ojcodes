#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

LL fastpw(LL a, LL pw) {
    LL ans = 1;
    while (pw > 0) {
        if (pw % 2 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        pw >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL n; cin >> n;
    if (n % 2 == 0) {
        LL len = n / 2;
        LL block = fastpw(fastpw(2, len), len); // 2^(len * len)
        LL ans = (fastpw(block, 4) + block + fastpw(block, 2) + block) % MOD;
        cout << ans * fastpw(4, MOD-2) % MOD << "\n";
    } else {
        LL len = n / 2;
        LL block = fastpw(fastpw(2, len), len); // 2^(len * len)
        LL block_cnt = max(1ll, block * fastpw(2, len)) % MOD;
        LL A = fastpw(fastpw(2, n), n);
        LL B = 2 * block_cnt % MOD;
        LL C = 2 * block_cnt * block_cnt % MOD;
        LL ans = (A + B + C + B) % MOD;
        cout << ans * fastpw(4, MOD-2) % MOD << "\n";
    }
}