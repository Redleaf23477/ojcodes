#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL n; cin >> n;
    cout << 26 + (5 + n) * (n - 5 + 1) / 2 + (6 + n + 1) * (n + 1 - 6 + 1) / 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



