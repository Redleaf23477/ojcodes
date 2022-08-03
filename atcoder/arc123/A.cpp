#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    LL a, b, c; cin >> a >> b >> c;
    if (a > c) swap(a, c);
    LL ans = 0;
    if (b < a) ans += a - b, b = a;
    LL d1 = b - a, d2 = c - b;
    LL d3 = abs(d2 - d1);
    if (d2 > d1) {
        cout << ans + ((d3 + 1) / 2) + (d3 % 2 == 1) << "\n";
    } else {
        cout << ans + d3 << "\n";
    }

}

