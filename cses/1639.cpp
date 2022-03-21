#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    string a, b; cin >> a >> b;
    const int INF = a.size() + b.size();
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, INF));
    dp[0][0] = 0;
    for (int j = 0; j <= (int)b.size(); j++) dp[0][j] = j;
    for (int i = 1; i <= (int)a.size(); i++) {
        dp[i][0] = i;
        for (int j = 1; j <= (int)b.size(); j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            dp[i][j] = min({dp[i][j], dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
        }
    }
    cout << dp[a.size()][b.size()] << "\n";
}

