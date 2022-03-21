#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int R, C; cin >> R >> C;
    vector<vector<int>> dp(R+1, vector<int>(C+1, R * C));
    for (int i = 1; i <= min(R, C); i++) dp[i][i] = 0;

    for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++) {
        // horizontal cut
        for (int up = 1; up < r; up++) {
            dp[r][c] = min(dp[r][c], dp[up][c] + dp[r-up][c] + 1);
        }
        // vertical cut
        for (int left = 1; left < c; left++) {
            dp[r][c] = min(dp[r][c], dp[r][left] + dp[r][c-left] + 1);
        }
    }

    cout << dp[R][C] << "\n";
}

