#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int x, k; cin >> x >> k;
    if (x % k != 0) {
        cout << 1 << "\n";
        cout << x << "\n";
    } else {
        cout << 2 << "\n";
        cout << x + 1 << " " << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



