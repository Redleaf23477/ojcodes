#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s, t; cin >> s >> t;
    // dp[i][j][k]: consider s[0:i] and t[0:j], in state k (k%2 == 0: a_{k/2}; k%2 == 1: p_{k/2})
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(k+k+1, -5000)));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) dp[i][0][0] = 0;
    for (int j = 1; j <= m; j++) dp[0][j][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) for (int seg = 0; seg < k+k+1; seg++) {
        char ch_s = s[i-1], ch_t = t[j-1];
        if (seg % 2 == 0) {
            // unmatched parts
            // form new unmatched segments
            if (seg != 0) {
                dp[i][j][seg] = max({dp[i][j][seg], dp[i][j][seg-1], dp[i-1][j][seg-1], dp[i][j-1][seg-1]});
            }
            // extend old unmatch segments
            dp[i][j][seg] = max({dp[i][j][seg], dp[i-1][j][seg], dp[i][j-1][seg]});
        } else {
            // matched parts
            if (ch_s == ch_t) {
                // form new segment
                dp[i][j][seg] = max(dp[i][j][seg], dp[i-1][j-1][seg-1] + 1);
                // extend old segment
                dp[i][j][seg] = max(dp[i][j][seg], dp[i-1][j-1][seg] + 1);
            }
        }
    }
    /*
    for (int seg = 0; seg < k+k+1; seg++) {
        cerr << "k = " << seg << endl;
        for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) {
            cerr << dp[i][j][seg] << " \n"[j==n];
        }
    }
    */
    cout << dp[n][m][k+k] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



