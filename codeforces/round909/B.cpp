#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    partial_sum(arr.begin(), arr.end(), arr.begin());
    LL ans = 0;
    for (int k = 1; k <= n; k++) {
        if (n % k != 0) continue;
        LL mx = arr[k], mn = arr[k];
        for (int i = k; i <= n; i += k) {
            mx = max(mx, arr[i] - arr[i - k]);
            mn = min(mn, arr[i] - arr[i - k]);
        }
        ans = max(ans, mx - mn);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

