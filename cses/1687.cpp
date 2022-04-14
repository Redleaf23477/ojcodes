#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    int lgn = log2(n) + 1;
    vector<vector<int>> dp(lgn+1, vector<int>(n, 0));
    dp[0][0] = -1;
    for (int i = 1; i < n; i++) {
        int pa; cin >> pa; pa--;
        dp[0][i] = pa;
    }
    for (int k = 1; k <= lgn; k++) for (int i = 0; i < n; i++) {
        if (dp[k-1][i] == -1) dp[k][i] = -1;
        else dp[k][i] = dp[k-1][dp[k-1][i]];
    }
    while (q--) {
        int x, k; cin >> x >> k; x--;
        for (int i = 0; (k >> i) && x != -1; i++) {
            if ((k >> i) & 1) {
                x = dp[i][x];
            }
        }
        if (x == -1) cout << -1 << "\n";
        else cout << x+1 << "\n";
    }
}