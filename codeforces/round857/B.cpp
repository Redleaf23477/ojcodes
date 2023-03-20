#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int calc(int known, int unknown) {
    int ans = unknown;
    if (known <= 2) ans += known;
    else {
        ans += 2 + (known - 2) / 2;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    int known = 0, unknown = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) {
            unknown++;
        } else {
            known += unknown, unknown = 0;
        }
        ans = max(ans, calc(known, unknown));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



