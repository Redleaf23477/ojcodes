#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x] += 1;
    }
    if (mp.size() == 1) {
        cout << mp.begin()->second / 2 << "\n";
    } else {
        LL ans = 0, acc = 0;
        for (auto [x, cnt] : mp) {
            acc += cnt;
            ans = max(ans, acc * (n - acc));
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

