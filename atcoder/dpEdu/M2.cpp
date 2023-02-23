#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9 + 7;

LL mod_add(LL lhs, LL rhs) {
    lhs += rhs;
    if (lhs >= MOD) lhs -= MOD;
    return lhs;
}

LL mod_sub(LL lhs, LL rhs) {
    lhs -= rhs;
    if (lhs < 0) lhs += MOD;
    return lhs;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> arr(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    // dp[n][k]: consider first n people, I have used k candies
    // dp[n][k] = dp[n-1][k] + ... + dp[n-1][k-ai]
    vector<vector<LL>> dp(n+1, vector<LL>(k+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        // make prefix sum
        for (int j = 1; j <= k; j++) {
            dp[i-1][j] = mod_add(dp[i-1][j], dp[i-1][j-1]);
        }
        // get dp
        for (int j = 0; j <= k; j++) {
            int R = j;
            int L = j - arr[i] - 1;
            dp[i][j] = dp[i-1][R];
            if (L >= 0) dp[i][j] = mod_sub(dp[i][j], dp[i-1][L]);
        }
    }
    cout << dp[n][k] << "\n";
}

