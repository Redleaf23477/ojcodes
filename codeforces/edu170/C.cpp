#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, k; cin >> n >> k;
    map<int,int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (mp.count(x) == 0) mp[x] = 0;
        mp[x] += 1;
    }
    int ans = 0;

    int prev = -1, window = -1, acc = 0;
    for (auto [x, cnt] : mp) {
        if (x != prev + 1) {
            prev = x;
            window = 1;
            acc = cnt;
        } else {
            prev = x;
            window += 1;
            acc += cnt;

            if (window == k + 1) {
                acc -= mp[x - k];
                window -= 1;
            }
        }
        ans = max(ans, acc);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

