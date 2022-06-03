#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL fastpw(LL a, LL b, LL mod) {
    LL ans = 1;
    while (b) {
        if (b % 2 == 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        LL a, b; cin >> a >> b;
        cout << fastpw(a, b, 1e9+7) << "\n";
    }
}

