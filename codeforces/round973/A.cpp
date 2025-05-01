#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n, x, y; cin >> n >> x >> y;
    if (x < y) {
        cout << (n + x - 1) / x << "\n";
    } else {
        cout << (n + y - 1) / y << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

