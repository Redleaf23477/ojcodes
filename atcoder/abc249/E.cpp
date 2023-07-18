#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL N, P; cin >> N >> P;
    if (N == 1) { cout << 0 << "\n"; return; }
    // prefix sum of dp[len of S][len of T]
    vector<vector<LL>> dp(N + 1, vector<LL>(N + 1, 0));
    fill(dp[0].begin(), dp[0].end(), 1);
    // first push the case that the whole string contains only the same char
    for (int i = 1; i <= N; i++) {
        dp[i][1 + to_string(i).size()] = 26;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            LL add = 0;
            // add 1-9 char
            if (i > 1 && j > 2) {
                add += dp[i-1][j-2];
                if (i >= 10) add -= dp[i-10][j-2];
                else add -= dp[0][j-2];
            }
            // add 10-99 char
            if (i > 10 && j > 3) {
                add += dp[i-10][j-3];
                if (i >= 100) add -= dp[i-100][j-3];
                else add -= dp[0][j-3];
            }
            // add 100-999 char
            if (i > 100 && j > 4) {
                add += dp[i-100][j-4];
                if (i >= 1000) add -= dp[i-1000][j-4];
                else add -= dp[0][j-4];
            }
            // add 1000-3000 char
            if (i > 1000 && j > 5) {
                add += dp[i-1000][j-5];
                add -= dp[0][j-5];
            }
            add = (add % P + P) * 25 % P;
            dp[i][j] = (dp[i][j] + add + dp[i-1][j]) % P;
        }
    }

    /*
    cerr << "dp = " << endl;
    for (int i = 1; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            cerr << (dp[i][j] - dp[i-1][j] + P) % P << " ";
        }
        cerr << endl;
    }
    */

    LL ans = 0;
    for (int len = 1; len < N; len++) {
        ans = (ans + dp[N][len] - dp[N-1][len] + P) % P;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



