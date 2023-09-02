#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL INF = 1e18;

void solve() {
    int R, C; cin >> R >> C;
    vector<LL> cost_row(R), cost_col(C);
    for (auto &x : cost_row) cin >> x;
    for (auto &x : cost_col) cin >> x;

    vector<vector<int>> arr(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char ch; cin >> ch;
            arr[i][j] = ch - '0';
        }
    }

    // dp[r][c][how row r and col c is flipped] = cost
    vector dp(R, vector<vector<LL>>(C, vector<LL>(4, INF)));
    auto compute = [&](int i, int j, bool from_left, bool from_up) {
        for (int flip = 0; flip < 4; flip++) {
            int row_flip = flip & 1;
            int col_flip = (flip >> 1) & 1;
            int my_color = arr[i][j] ^ row_flip ^ col_flip;

            if (from_left) {
                int prev_flip = row_flip + ((my_color != (arr[i][j - 1] ^ row_flip)) << 1);
                LL my_cost = row_flip * cost_row[i] * (j == 0) + col_flip * cost_col[j];
                dp[i][j][flip] = min(dp[i][j][flip], dp[i][j - 1][prev_flip] + my_cost);
            }
            if (from_up) {
                int prev_flip = (my_color != (arr[i - 1][j] ^ col_flip)) + (col_flip << 1);
                LL my_cost = row_flip * cost_row[i] + col_flip * cost_col[j] * (i == 0);
                dp[i][j][flip] = min(dp[i][j][flip], dp[i - 1][j][prev_flip] + my_cost);
            }
        }
    };
    // i = 0
    dp[0][0][0] = 0;
    dp[0][0][1] = cost_row[0];
    dp[0][0][2] = cost_col[0];
    dp[0][0][3] = cost_row[0] + cost_col[0];
    for (int j = 1; j < C; j++) {
        compute(0, j, true, false);
    }
    // i > 1
    for (int i = 1; i < R; i++) {
        // j = 0
        compute(i, 0, false, true);
        // j > 1
        for (int j = 1; j < C; j++) {
            compute(i, j, true, true);
        }
    }
    cout << *min_element(dp[R - 1][C - 1].begin(), dp[R - 1][C - 1].end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



