#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    const LL MOD = 998244353;
    vector<LL> fac(1001, 1);
    for (int i = 1; i <= 1000; i++) fac[i] = fac[i-1] * i % MOD;
    while (T--) {
        int n; cin >> n;
        if (n % 2 == 1) cout << 0 << "\n";
        else cout << fac[n/2] * fac[n/2] % MOD << "\n";
    }
}

