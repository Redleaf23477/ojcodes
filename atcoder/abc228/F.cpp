#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

const int N = 1000, LG_N = log2(N)+1;

struct SparseTable2D {
    int n, lgn;
    int m, lgm;
    LL dp[N][LG_N][N][LG_N];
    void init(const vector<vector<LL>> &arr) {
        n = arr.size(), lgn = log2(n) + 1;
        m = arr[0].size(), lgm = log2(m) + 1;
        // 1D
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                dp[0][r][0][c] = arr[r][c];
            }
            for (int lg = 1; lg <= lgm; lg++) {
                for (int c = 0; c < m; c++) {
                    dp[0][r][lg][c] = max(dp[0][r][lg-1][c], dp[0][r][lg-1][c + (1<<(lg-1))]);
                }
            }
        }
        // 2D
        for (int lg_r = 1; lg_r <= lgn; lg_r++) for (int r = 0; r < n; r++) {
            for (int lg_c = 1; lg_c <= lgm; lg_c++) for (int c = 0; c < m; c++) {
                dp[lg_r][r][lg_c][c] = max(dp[lg_r-1][r][lg_c][c], dp[lg_r-1][r + (1<<(lg_r-1))][lg_c][c]);
            }
        }
    }
    LL query(int r1, int c1, int r2, int c2) {
        int lg_r = log2(r2 - r1 + 1);
        int lg_c = log2(c2 - c1 + 1);
        LL low_row = max(dp[lg_r][r1][lg_c][c1], dp[lg_r][r1][lg_c][c2 - (1 << lg_c) + 1]);
        LL high_row = max(dp[lg_r][r2 - (1 << lg_r) + 1][lg_c][c1], dp[lg_r][r2 - (1 << lg_r)][lg_c][c2 - (1 << lg_c) + 1]);
        return max(low_row, high_row);
    }
};

SparseTable2D sp;

LL sum(int r1, int r2, int c1, int c2, vector<vector<LL>> &arr) {
    return arr[r2][c2] - arr[r2][c1-1] - arr[r1-1][c2] + arr[r1-1][c1-1];
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int R, C, r1, c1, r2, c2; 
    cin >> R >> C >> r1 >> c1 >> r2 >> c2;
    r2 = min(r1, r2), c2 = min(c1, c2);
    vector<vector<LL>> arr(R+1, vector<LL>(C+1, 0));
    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) {
        cin >> arr[i][j];
    }
    for (int i = 1; i <= R; i++) for (int j = 1; j <= C; j++) {
        arr[i][j] += arr[i][j-1];
    }
    for (int j = 1; j <= C; j++) for (int i = 1; i <= R; i++) {
        arr[i][j] += arr[i-1][j];
    }
    
    /*
    for (int i = 0; i <= R; i++) for (int j = 0; j <= C; j++) {
        cerr << arr[i][j] << " \n"[j==C];
    }
    */
    
    if (r1 == r2 && c1 == c2) {
        cout << 0 << "\n";
    } else {
        vector<vector<LL>> sub(R+1, vector<LL>(C+1, 0));
        for (int i = 1; i + r2 - 1 <= R; i++) for (int j = 1; j + c2 - 1 <= C; j++) {
            sub[i][j] = sum(i, i+r2-1, j, j+c2-1, arr);
        }
        sp.init(sub);
        LL ans = 0;
        for (int i = 1; i + r1-1 <= R; i++) for (int j = 1; j + c1-1 <= C; j++) {
            LL s = sum(i, i + r1 - 1, j, j + c1 - 1, arr);
            LL q = sp.query(i, j, i+r1-r2, j+c1-c2);
            ans = max(ans, s - q);
        }
        cout << ans << "\n";
    }
}

