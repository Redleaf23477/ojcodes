#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL n, B, x, y; cin >> n >> B >> x >> y;
    LL ans = 0, a = 0;
    for (int i = 0; i < n; i++) {
        if (a + x <= B) a += x;
        else a -= y;
        ans += a;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

