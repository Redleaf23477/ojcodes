#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<int> dp(n + 1, 0);
    vector<int> suff_min(n + 1, 0);
    suff_min[n] = n;
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = n - i;
        int j = i + arr[i] + 1;
        if (j <= n) {
            dp[i] = min(dp[i], suff_min[j] - j);
        }
        // dp[i] = min_k = j to n: k - j + dp[k]
        suff_min[i] = min(suff_min[i + 1], dp[i] + i);
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        ans = min(ans, i + dp[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

