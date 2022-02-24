#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL MOD = 1e9+7;

struct Mat : public vector<vector<LL>> {
    Mat (int n, int m, bool identy=false) : vector<vector<LL>>(n, vector<LL>(m, 0)) {
        if (identy && n == m) {
            for (int i = 0; i < n; i++) (*this)[i][i] = 1;
        }
    }
    Mat operator * (Mat that) {
        Mat ans(row_num(), that.col_num());
        for (size_t i = 0; i < ans.row_num(); i++) 
            for (size_t j = 0; j < ans.col_num(); j++) 
                for (size_t k = 0; k < col_num(); k++) {
                    ans[i][j] = (ans[i][j] + (*this)[i][k] * that[k][j]) % MOD;
                }
        return ans;
    };
    size_t row_num() { return size(); }
    size_t col_num() { return (*this)[0].size(); }
};

Mat fastpw(Mat m, LL p) {
    Mat ans(m.row_num(), m.col_num(), true);
    while (p > 0) {
        if (p % 2 == 1) ans = ans * m;
        m = m * m;
        p /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    LL n; cin >> n;
    if (n == 0) cout << 0 << "\n";
    else {
        Mat m(2, 2);
        m[0][0] = m[0][1] = m[1][0] = 1;
        m = fastpw(m, n-1);
        Mat x(2, 1);
        x[0][0] = 1, x[1][0] = 0;
        Mat ans = m * x;
        cout << ans[0][0] << "\n";
    }
}

