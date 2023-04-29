#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
const LL e9 = 1e9;

void solve() {
    LL a, b; cin >> a >> b;
    LL g = gcd(a, b);
    if (g == 1) {
        cout << 1 << "\n";
        cout << a << " " << b << "\n";
    } else {
        cout << 2 << "\n";
        LL a2 = a / g, b2 = b / g;
        LL k = b2 - 1;
        cout << a << " " << b - k << "\n";
        cout << a << " " << b << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



