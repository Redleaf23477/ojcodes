#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr int INF = 1e9 + 9;


int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    vector<int> arr(n); 
    for (auto &x : arr) cin >> x;

    int lgn = log2(n) + 2;
    vector<vector<int>> dp(lgn, vector<int>(n, INF));
    for (int i = 0; i < n; i++) {
        dp[0][i] = arr[i];
    }
    for (int k = 1; k < lgn; k++) {
        for (int i = 0; i < n; i++) {
            dp[k][i] = min(dp[k-1][i], (i+(1<<(k-1)) < n? dp[k-1][i+(1<<(k-1))] : INF));
        }
    }
    /*
    cerr << "dp = " << endl;
    for (int i = 0; i < n; i++) {
        cerr << i << " => ";
        for (int k = 0; k < lgn; k++) cerr << dp[k][i] << " ";
        cerr << endl;
    }
    */
    while (q--) {
        int l, r; cin >> l >> r; l--, r--;
        int len = r - l + 1;
        int lg_len = log2(len);
        cout << min(dp[lg_len][l], dp[lg_len][r - (1<<lg_len) + 1]) << "\n";
    }
}

