#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<LL,LL>;
constexpr LL INF = 3 * 1000ll * (LL)1e9;

void solve() {
    int n, p; cin >> n >> p;
    vector<T> arr(n);
    for (auto &[low, high] : arr) {
        LL x; 
        low = 1e9+1, high = 0;
        for (int i = 0; i < p; i++) {
            cin >> x;
            low = min(low, x);
            high = max(high, x);
        }
    }

    vector<vector<LL>> dp(n, vector<LL>(2, INF));
    {
        auto [low, high] = arr[0];
        dp[0][0] = high + high - low;
        dp[0][1] = high;
    }
    for (int i = 1; i < n; i++) {
        auto [p_low, p_high] = arr[i-1];
        auto [n_low, n_high] = arr[i];
        // dp[i-1][0] -> dp[i][0]
        dp[i][0] = min(dp[i][0], dp[i-1][0] + abs(n_high - p_low) + abs(n_low - n_high));
        // dp[i-1][1] -> dp[i][0]
        dp[i][0] = min(dp[i][0], dp[i-1][1] + abs(n_high - p_high) + abs(n_low - n_high));
        // dp[i-1][0] -> dp[i][1]
        dp[i][1] = min(dp[i][1], dp[i-1][0] + abs(n_low - p_low) + abs(n_high - n_low));
        // dp[i-1][1] -> dp[i][1]
        dp[i][1] = min(dp[i][1], dp[i-1][1] + abs(n_low - p_high) + abs(n_high - n_low));
    }
    cout << min(dp[n-1][0], dp[n-1][1]) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

