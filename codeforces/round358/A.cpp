#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL n, m; cin >> n >> m;
    LL ans = 0;
    for (LL rx = 0; rx <= 4; rx++) {
        LL ry = (5 - rx) % 5;
        LL x = n / 5 + (rx != 0 && n % 5 >= rx);
        LL y = m / 5 + (ry != 0 && m % 5 >= ry);
        ans += x * y;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



