#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<LL>> dp(n, vector<LL>(m+2, 0));
    if (arr[0] == 0) fill(dp[0].begin()+1, dp[0].end() - 1, 1);
    else dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
                dp[i][j] %= MOD;
            }
        } else {
            int j = arr[i];
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
            dp[i][j] %= MOD;
        }
    }
    cout << accumulate(dp[n-1].begin(), dp[n-1].end(), 0ll) % MOD << "\n";
}

