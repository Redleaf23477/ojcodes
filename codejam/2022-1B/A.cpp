#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    deque<int> arr(n);
    for (auto &x : arr) cin >> x;
    int ans = 0, mx = -1;
    for (int i = 0; i < n; i++) {
        int x;
        if (arr.front() < arr.back()) {
            x = arr.front(); arr.pop_front();
        } else {
            x = arr.back(); arr.pop_back();
        }
        if (x >= mx) ans += 1;
        mx = max(mx, x);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

