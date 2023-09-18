#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n, k, x; cin >> n >> k >> x;
    LL mx = (k == x? k - 1 : x);
    if (n < k || k - 1 > x) {
        cout << -1 << "\n"; return;
    } else {
        LL ans = k * (k - 1) / 2;
        ans += mx * (n - k);
        cout << ans << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

