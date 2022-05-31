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
    int n, m, k; cin >> n >> m >> k;
    Mat G(n, n, false);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        G[u-1][v-1] += 1;
    }
    Mat Gk = fastpw(G, k);
    cout << Gk[0][n-1] << "\n";
}