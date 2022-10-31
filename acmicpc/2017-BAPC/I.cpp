#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Solver {
    static const int INF = 100000;
    int R, C;
    // dp[lower_left_position] = maximize difference
    vector<vector<int>> dp1, dp2;
    Solver(int _R, int _C) : R(_R), C(_C), dp1(R+2, vector<int>(C+2, -INF)) {
        for (int i = 0; i < C+2; i++) dp1[0][i] = dp1[R+1][i] = 0;
        for (int i = 0; i < R+2; i++) dp1[i][0] = dp1[i][C+1] = 0;
        dp2 = dp1;
    }
    LL f(int lower_row, int lower_col) {
        if (dp1[lower_row][lower_col] != -INF) {
            return dp1[lower_row][lower_col];
        }
        int height = lower_row;
        int width = C - lower_col + 1;
        LL opt = -INF;
        for (int pick = 1; pick <= width; pick++) {
            LL gain = 0;
            if (pick % 2 == 1 && height % 2 == 1) {
                gain = (lower_row + lower_col) % 2 == 0? 1 : -1;
            }
            gain -= g(lower_row, lower_col + pick);
            opt = max(opt, gain);
        }
        return dp1[lower_row][lower_col] = opt;
    }
    LL g(int lower_row, int lower_col) {
        if (dp2[lower_row][lower_col] != -INF) {
            return dp2[lower_row][lower_col];
        }
        int height = lower_row;
        int width = C - lower_col + 1;
        LL opt = -INF;
        for (int pick = 1; pick <= height; pick++) {
            LL gain = 0;
            if (pick % 2 == 1 && width % 2 == 1) {
                gain = (lower_row + lower_col) % 2 == 0? 1 : -1;
            }
            gain -= f(lower_row - pick, lower_col);
            opt = max(opt, gain);
        }
        return dp2[lower_row][lower_col] = opt;
    }
    LL run() {
        LL ans = f(R, 1);
        /*
        cerr << "DP1: " << endl;
        for (auto &row : dp1) {
            for (auto &col : row) {
                cerr << col << " ";
            }
            cerr << endl;
        }
        cerr << "DP2: " << endl;
        for (auto &row : dp2) {
            for (auto &col : row) {
                cerr << col << " ";
            }
            cerr << endl;
        }
        */
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int R, C; cin >> R >> C;
    cout << Solver(R, C).run() << "\n";
}

