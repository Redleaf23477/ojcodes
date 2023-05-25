#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL n; cin >> n;
    for (LL a = 0; a * 1234567 <= n; a++) {
        LL m = n - 1234567 * a;
        for (LL b = 0; b * 123456 <= m; b++) {
            LL p = m - b * 123456;
            if (p % 1234 == 0) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



