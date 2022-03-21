#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL INF = 1e18;

struct SparseTable {
    int n, lgn;
    vector<vector<LL>> dp;
    SparseTable(const vector<LL> &arr) : n(arr.size()), lgn(log2(n) + 1), dp(lgn+1, vector<LL>(n, -INF)) {
        for (int i = 0; i < n; i++) {
            dp[0][i] = arr[i];
        }
        for (int k = 1; k <= lgn; k++) {
            for (int i = 0; i < n; i++) {
                int j = min(n-1, i + (1 << (k-1)));
                dp[k][i] = max(dp[k-1][i], dp[k-1][j]);
            }
        }
    }
    LL query(int l, int r) {
        int len = r - l + 1, lg_len = log2(len);
        int small_len = 1 << lg_len;
        return max(dp[lg_len][l], dp[lg_len][r - small_len + 1]);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, a, b; cin >> n >> a >> b;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    partial_sum(arr.begin(), arr.end(), arr.begin());

    SparseTable st(arr);
    LL ans = -INF;
    for (int i = 0; i <= n-a; i++) {
        int L = i + a - 1, R = min(n - 1, i + b - 1);
        LL sub = (i == 0? 0 : arr[i-1]);
        ans = max(ans, st.query(L, R) - sub);
    }
    cout << ans << "\n";
}
