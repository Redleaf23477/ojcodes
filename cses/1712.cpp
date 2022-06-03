#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL fastpw(LL a, LL b, LL mod) {
    LL ans = (a != 0 && a % mod == 0? 0 : 1);
    while (b) {
        if (b % 2 == 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    constexpr LL P = 1e9+7;
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        LL a, b, c; cin >> a >> b >> c;
        if (a == 0) {
            if (b == 0) {
                if (c == 0) cout << 0 << "\n";
                else cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else {
            LL tmp = fastpw(b, c, P-1);
            cout << fastpw(a, tmp, P) << "\n";
        }
    }
}

