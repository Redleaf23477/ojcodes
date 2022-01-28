#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        LL l, r; cin >> l >> r;
        LL ans = 0;
        while (r > 0) {
            ans += r - l;
            l /= 10, r /= 10;
        }
        cout << ans << endl;
    }
}

