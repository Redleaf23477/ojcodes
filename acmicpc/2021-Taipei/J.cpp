#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL n, s, p; cin >> n >> s >> p;
    LL u = n - s - 1;
    vector<LL> trash(s); for (auto &x : trash) cin >> x;

    LL ans = 0;
    LL x = min(s, p), y = min(p - x, u);
    LL a = s - x, b = u - y;
    // root to all
    ans += x + 2 * y + 3 * a + 2 * b;
    // 1st to 1st
    ans += 2 * x * (x-1) / 2 + 4 * y * (y-1) / 2 + 3 * x * y;
    // 2nd to 2nd
    ans += 4 * a * (a-1) / 2 + 2 * b * (b-1) / 2 + 3 * a * b;
    // 2nd to 1st
    ans += 2 * a + 1 * b;
    ans += 4 * a * (x-1) + 3 * b * (x-1);
    if (y > 0) ans += 5 * a * y + 4 * b * y;
    
    cout << ans * 2 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

