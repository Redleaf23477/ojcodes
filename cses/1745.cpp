#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int sum = accumulate(arr.begin(), arr.end(), 0);

    vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
    for (int i = 1; i <= n; i++) {
        int x = arr[i-1];
        for (int s = 1; s <= sum; s++) {
            if (i - 1 >= 0) dp[i][s] = dp[i-1][s];
            if (s - x == 0) dp[i][s] = true;
            if (s - x >= 0 && dp[i-1][s - x]) dp[i][s] = true;
        }
    }

    int ans = accumulate(dp.back().begin(), dp.back().end(), 0);
    cout << ans << "\n";
    for (int s = 1; s <= sum; s++) {
        if (dp.back()[s]) cout << s << " ";
    }
    cout << "\n";
}

