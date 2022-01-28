#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL MOD = 1e9+7;

LL fastpw(LL n, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * n % MOD;
        n = n * n % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    LL n; cin >> n;
    cout << fastpw(2, n) << "\n";
}

