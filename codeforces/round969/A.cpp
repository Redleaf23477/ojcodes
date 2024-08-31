#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int l, r; cin >> l >> r;
    if (l % 2 == 0) l++;
    if (r % 2 == 1) r++;
    if (l > r) cout << 0 << "\n";
    else cout << (r - l + 1) / 4 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

