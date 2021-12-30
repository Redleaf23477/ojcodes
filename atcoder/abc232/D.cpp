#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int R, C; cin >> R >> C;
    vector<vector<char>> maze(R, vector<char>(C)); {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                cin >> maze[r][c];
            }
        }
    }
    vector<vector<int>> dp(R, vector<int>(C, -1)); {
        dp[0][0] = 1;
        for (int i = 1; i < C; i++) {
            if (maze[0][i] == '.') dp[0][i] = dp[0][i-1] + 1;
            else break;
        }
        for (int i = 1; i < R; i++) {
            if (maze[i][0] == '.') dp[i][0] = dp[i-1][0] + 1;
            else break;
        }
        for (int r = 1; r < R; r++) for (int c = 1; c < C; c++) {
            if (maze[r][c] == '#') continue;
            if (dp[r-1][c] != -1) dp[r][c] = max(dp[r][c], dp[r-1][c] + 1);
            if (dp[r][c-1] != -1) dp[r][c] = max(dp[r][c], dp[r][c-1] + 1);
        }
    }
    int ans = 1; {
        for (const auto &row : dp) {
            ans = max(ans, *max_element(row.begin(), row.end()));
        }
    }
    cout << ans << endl;
}