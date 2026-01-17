#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    size_t p, q; cin >> p >> q;
    size_t x, y; cin >> x >> y;

    if (p <= x && x < p + 100 && q <= y && y < q + 100) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

