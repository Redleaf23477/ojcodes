#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve_small() {
    int n; cin >> n;
    map<LL,LL> mp;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        mp[x] += 1;
    }
    LL ans = 0;
    for (auto [val, cnt] : mp) {
        // b = 1
        if (cnt >= 3) {
            ans += cnt * (cnt-1) * (cnt-2);
        }
        // b > 1
        for (LL b = 2; val * b * b <= 1'000'000; b++) {
            LL jmp1 = val * b;
            LL jmp2 = jmp1 * b;
            if (mp.count(jmp1) != 0 && mp.count(jmp2) != 0) {
                ans += cnt * mp[jmp1] * mp[jmp2];
            }
        }
    }
    cout << ans << "\n";
}

void solve() {
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        // solve();
        solve_small();
    }
}




