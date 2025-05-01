#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL l, r; cin >> l >> r;
    LL delta = 1;
    LL ans = 1, x = l;
    while (x + delta <= r) {
        x += delta;
        ans += 1;
        delta += 1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

