#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool good(string a) {
    for (size_t i = 1; i < a.size(); i++) {
        if (a[i-1] == a[i]) return false;
    }
    return true;
}

LL solve(string b) {

    vector<bool> b_still_good(b.size(), true);
    for (size_t i = 1; i < b.size(); i++) {
        b_still_good[i] = b_still_good[i-1] && (b[i] != b[i-1]);
    }

    int n = b.size();
    vector<vector<LL>> dp(n, vector<LL>(10, 0)); // the first n digits a < the first n digits of b, ending with j
    for (int i = 1; i < b[0]-'0'; i++) dp[0][i] = 1;
    for (int i = 1; i < n; i++) for (int j = 0; j < 10; j++) {
        if (j < b[i] - '0' && j != b[i-1] - '0') {
            dp[i][j] += b_still_good[i-1];
        }
        for (int k = 0; k < 10; k++) if (j != k) {
            dp[i][j] += dp[i-1][k];
        }
        if (j != 0) dp[i][j] += 1;  // 0....0j
    }
    
    /*
    cerr << b << endl;
    for (int i = 0; i < n; i++) {
        cerr << i << ": ";
        for (int j = 0; j < 10; j++) {
            cerr << "(" << j << "," << dp[i][j] << ")";
        }
        cerr << endl;
    }
    cerr << ">>>" << accumulate(dp[n-1].begin(), dp[n-1].end(), 0ll) + good(b) << endl;
    */
    
    return accumulate(dp[n-1].begin(), dp[n-1].end(), 0ll) + good(b); 
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    string a, b; cin >> a >> b;
    /*
    if (a.size() != b.size()) {
        a = string(b.size() - a.size(), '0') + a;
    }
    */
    LL ans = solve(b) - solve(a) + good(a);
    if (a == "0") ans += 1;  // since I count only number > 0
    if (b == "0") ans -= 1;
    cout << ans << "\n";
}
