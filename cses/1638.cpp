#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<string> maze(n);
    for (auto &x : maze) cin >> x;
    vector<vector<LL>> dp(n, vector<LL>(n, 0));
    dp[0][0] = (maze[0][0] == '.');
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (maze[i][j] == '*') continue;
        if (i-1 >= 0 && maze[i-1][j] != '*') dp[i][j] += dp[i-1][j];
        if (j-1 >= 0 && maze[i][j-1] != '*') dp[i][j] += dp[i][j-1];
        dp[i][j] %= MOD;
    }
    cout << dp[n-1][n-1] << "\n";
}