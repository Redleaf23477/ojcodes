#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    int lg = 32;
    vector<vector<int>> dp(lg, vector<int>(n));
    for (int i = 0; i < n; i++) {
        cin >> dp[0][i]; dp[0][i]--;
    }
    for (int j = 1; j < lg; j++) {
        for (int i = 0; i < n; i++) {
            dp[j][i] = dp[j-1][dp[j-1][i]];
        }
    }
    while (q--) {
        int u, k; cin >> u >> k; u--;
        for (int s = 0; s < lg; s++) {
            if ((k >> s) & 1) {
                u = dp[s][u];
            }
        }
        cout << u + 1 << "\n";
    }
}

