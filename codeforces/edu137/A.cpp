#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int use = 10 - n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
        }
        // C(use, 2) * 4!/2!/2!
        int ans = use * (use - 1) / 2 * 4 * 3 / 2;
        cout << ans << "\n";
    }
}

