#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL l, r, k; cin >> l >> r >> k;
    if (k == 1) cout << r - l + 1 << "\n";
    else {
        LL mx = r / k;
        if (mx >= l) cout << mx - l + 1 << "\n";
        else cout << 0 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

