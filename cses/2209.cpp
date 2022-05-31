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
    // burnside lemma
    LL n, m; cin >> n >> m;
    LL ans = 0;
    for (int r = 1; r <= n; r++) {
        LL g = gcd(r, n);
        ans = (ans + fastpw(m, g)) % MOD;
    }
    cout << ans * fastpw(n, MOD-2) % MOD << "\n";
}