#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

struct Mat : public vector<vector<LL>> {
    Mat(int n, int m, bool is_I = true) : vector<vector<LL>>(n, vector<LL>(m, 0)) {
        if (is_I and n == m) {
            for (int i = 0; i < n; i++) (*this)[i][i] = 1;
        }
    }
    Mat operator * (Mat that) {
        Mat ans(this->size(), that[0].size(), false);
        for (size_t i = 0; i < ans.size(); i++) for (size_t j = 0; j < ans[0].size(); j++) for (size_t k = 0; k < that.size(); k++) {
            ans[i][j] = ((*this)[i][k] * that[k][j] % MOD + ans[i][j]) % MOD;
        }
        return ans;
    }
};

Mat fastpw(Mat m, LL p) {
    Mat ans(m.size(), m.size());
    while (p > 0) {
        if (p % 2 == 1) ans = ans * m;
        m = m * m;
        p >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL n; cin >> n;
    Mat M(6, 6, false);
    for (int i = 1; i < 6; i++) M[i-1][i] = 1;
    for (int i = 0; i < 6; i++) M[5][i] = 1;

    Mat A = fastpw(M, n);
    Mat x(6, 1, false);
    x[0][0] = 1, x[1][0] = 1, x[2][0] = 2, x[3][0] = 4, x[4][0] = 8, x[5][0] = 16;

    Mat b = A * x;
    cout << b[0][0] << "\n";

}