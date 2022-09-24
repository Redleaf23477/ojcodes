#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        LL m, n; cin >> m >> n;
        if (m == 1) {
            if (n == 0) cout << 1 << "\n";
            else cout << 2 << "\n";
        } else {
            if (n == 0) cout << (1ll << m) << "\n";
            else cout << (1ll << m) - 1 << "\n";
        }
    }
}

