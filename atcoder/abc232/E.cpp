#include <bits/stdc++.h>
using namespace std;
using LL = long long;

constexpr LL MOD = 998244353;

struct Mat : public vector<vector<LL>> {
    Mat(int R, int C, bool I = false) : vector<vector<LL>>(R, vector<LL>(C, 0)) {
        if (I) {
            for (int r = 0; r < R; r++) (*this)[r][r] = 1;
        }
    }
    size_t row_num() const { return (*this).size(); }
    size_t col_num() const { return (*this)[0].size(); }
    Mat operator * (Mat rhs) {
        auto &lhs = *this;
        Mat ans(lhs.row_num(), rhs.col_num());
        for (size_t i = 0; i < ans.row_num(); i++)
            for (size_t j = 0; j < ans.col_num(); j++)
                for (size_t k = 0; k < rhs.row_num(); k++) {
                    ans[i][j] = (ans[i][j] + lhs[i][k] * rhs[k][j] % MOD) % MOD;
                }
        return ans;
    }
    Mat operator + (Mat rhs) {
        Mat ans(*this);
        for (size_t i = 0; i < ans.row_num(); i++) {
            for (size_t j = 0; j < ans.col_num(); j++) {
                ans[i][j] = (ans[i][j] + rhs[i][j]) % MOD;
            }
        }
        return ans;
    }
};

Mat fastpw(Mat m, LL p) {
    Mat ans(m.row_num(), m.row_num(), true);
    while (p > 1) {
        if (p % 2 == 1) ans = ans * m;
        m = m * m, p /= 2;
    }
    return ans * m;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL H, W, K; cin >> H >> W >> K;
    LL r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    Mat A(9, 9); {
        vector<LL> c_len {max(0ll, c1-1), 1, max(0ll, W-c1)};
        vector<LL> r_len {max(0ll, r1-1), 1, max(0ll, H-r1)};
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) {
            for (int u = 0; u < 3; u++) for (int v = 0; v < 3; v++) {
                if (r_len[i] > 0 && c_len[j] > 0 && r_len[u] > 0 && c_len[v] > 0) {
                    A[u*3+v][i*3+j] = ((i==u) * c_len[j] + (j==v) * r_len[i] - (i==u) * (j==v) * 2 + MOD) % MOD;
                }
            }
        }
        /*
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cerr << A[i][j] << " ";
            }
            cerr << endl;
        }
        */
    }
    Mat x(9, 1); {
        x[4][0] = 1;  // other is 0
    }
    Mat Ak = fastpw(A, K);
    Mat B = Ak * x;

    /*
    cerr << "-----" << endl;
    for (size_t i = 0; i < Ak.row_num(); i++) {
        for (size_t j = 0; j < Ak.col_num(); j++) {
            cerr << Ak[i][j] << " ";
        }
        cerr << endl;
    }
    cerr << "-----" << endl;
    for (size_t i = 0; i < B.row_num(); i++) {
        for (size_t j = 0; j < B.col_num(); j++) {
            cerr << B[i][j] << " ";
        }
        cerr << endl;
    }
    */

    auto f = [](int x1, int x2) {
        if (x2 < x1) return 0;
        else if (x2 == x1) return 1;
        else return 2;
    };
    int idx = 3 * f(r1, r2) + f(c1, c2);
    cout << B[idx][0] << endl;
}
