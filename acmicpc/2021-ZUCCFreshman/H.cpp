#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL fastpw(LL x, LL pw, LL MOD) {
    LL ans = 1;
    while (pw > 0) {
        if (pw % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        pw /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    const LL MOD = 998244353;
    while (T--) {
        LL n; cin >> n;
        // ans = 2**n - 1
        cout << ((fastpw(2, n, MOD) - 1) % MOD + MOD) % MOD << "\n";
    }
}

