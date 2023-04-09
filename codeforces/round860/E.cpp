#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n); 
    for (auto &x : arr) cin >> x;

    // upper bound for a suffix [i:n) = 2 steps
    // --> change arr[i] to 1, arr[i+1] to (n-i+1)
    vector<int> ans(n, 2);

    // 1 step strategy for a suffix [i:n)
    // --> change the number of test cases in arr[i]
    // --> change arr[i+1] so that the following becomes a valid test case
    // 0 step strategy
    // --> arr[i] is identical to number of test cases
    
    // dp[i][j] = num of test cases in suffix [i:n) with j modifies (j = 0 or 1)
    const int INF = 1e6;
    vector<vector<int>> dp(n, vector<int>(2, INF));
    for (int i = n-1, suff = 0; i >= 0; i--) {
        int next_test = i + arr[i] + 1;
        // dp[i][1]
        dp[i][1] = suff + 1;
        if (next_test < n && dp[next_test][1] != INF) {
            dp[i][1] = max(dp[i][1], dp[next_test][1] + 1);
        }
        // dp[i][0]
        if (next_test == n) {
            dp[i][0] = 1;
            suff = max(suff, dp[i][0]);
        } else if (next_test < n && dp[next_test][0] != INF) {
            dp[i][0] = dp[next_test][0] + 1;
            suff = max(suff, dp[i][0]);
        }
    }

    // can ans be 1 or 0?
    ans[n-1] = (arr[n-1] == 0? 0 : 1);
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] == dp[i+1][0]) ans[i] = 0;
        else if (dp[i+1][0] != INF) ans[i] = 1;
        else if (arr[i] != 0 && arr[i] <= dp[i+1][1]) ans[i] = 1;
    }

    // print ans
    for (int i = 0; i < n-1; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



