#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Matrix = vector<vector<double>>;

bool legal(int r, int c) {
    return 0 <= r && r < 8 && 0 <= c && c < 8;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector<int> dr {-1, 1, 0, 0}, dc {0, 0, 1, -1};

    Matrix empty_prob(8, vector<double>(8, 1));

    auto run = [&](int sr, int sc, int n) {
        vector<Matrix> mat(2, Matrix(8, vector<double>(8, 0)));

        mat[1][sr][sc] = 1;
        for (int i = 0; i < n; i++) {
            Matrix &source = mat[1 - i % 2];
            Matrix &dest = mat[i % 2];

            dest = Matrix(8, vector<double>(8, 0));
            for (int r = 0; r < 8; r++) for (int c = 0; c < 8; c++) {
                int ok_dir = 0;
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (legal(nr, nc)) {
                        ok_dir++;
                    }
                }
                for (int d = 0; d < 4; d++) {
                    int nr = r + dr[d], nc = c + dc[d];
                    if (legal(nr, nc)) {
                        dest[nr][nc] += source[r][c] * (1.0 / ok_dir);
                    }
                }
            }
        }

        Matrix &ans = mat[1 - n % 2];
        for (int r = 0; r < 8; r++) for (int c = 0; c < 8; c++) {
            empty_prob[r][c] *= (1.0 - ans[r][c]);
        }
    };

    int n; cin >> n;
    for (int sr = 0; sr < 8; sr++) for (int sc = 0; sc < 8; sc++) {
        run(sr, sc, n);
    }

    double empty_exp = 0;
    for (int r = 0; r < 8; r++) for (int c = 0; c < 8; c++) {
        empty_exp += empty_prob[r][c];
    }
    cout << fixed << setprecision(6) << empty_exp << "\n";
}
