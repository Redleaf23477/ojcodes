#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int x, y;
    cin >> x >> y;
    x = abs(x), y = abs(y);
    int ans = 2 * min(x, y);
    int rest = max(x, y) - min(x, y);
    ans += rest + max(0, rest - 1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



