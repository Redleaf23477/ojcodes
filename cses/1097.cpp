#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<LL>> dp(n, vector<LL>(n, -INF));
    for (int i = 0; i < n; i++) {
        if (n % 2 == 1) {
            dp[i][i] = arr[i];
        } else {
            dp[i][i] = 0;
        }
    }

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            if (len % 2 == n % 2) {
                dp[l][r] = max(dp[l+1][r] + arr[l], dp[l][r-1] + arr[r]);
            } else {
                dp[l][r] = min(dp[l+1][r], dp[l][r-1]);
            }
        }
    }
    cout << dp[0][n-1] << "\n";

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dp[i][j] == -INF) cerr << "X ";
            else cerr << dp[i][j] << " ";
        }
        cerr << endl;
    }
    */
}

