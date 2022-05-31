#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

constexpr LL INF = 1e18 + 1e18;

struct Mat : public vector<vector<LL>> {
    Mat(int n, int m, bool is_I = true) : vector<vector<LL>>(n, vector<LL>(m, INF)) {
        if (is_I and n == m) {
            for (int i = 0; i < n; i++) (*this)[i][i] = 0;
        }
    }
    Mat operator * (Mat that) {
        Mat ans(this->size(), that[0].size(), false);
        for (size_t k = 0; k < that.size(); k++) for (size_t i = 0; i < ans.size(); i++) for (size_t j = 0; j < ans[0].size(); j++) {
            ans[i][j] = min(((*this)[i][k] + that[k][j]), ans[i][j]);
        }
        return ans;
    }
};

Mat fastpw(Mat m, LL p) {
    Mat ans(m.size(), m.size(), true);
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
        LL u, v, w; cin >> u >> v >> w;
        G[u-1][v-1] = min(G[u-1][v-1], w);
    }
    Mat Gk = fastpw(G, k);
    LL ans = Gk[0][n-1];
    if (ans == INF) ans = -1;
    cout << ans << "\n";
}