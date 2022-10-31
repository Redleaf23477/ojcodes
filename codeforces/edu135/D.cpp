#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string str; cin >> str;
    int n = str.size();
    // 0: draw
    // 1: alice
    // 2: bob
    vector<vector<int>> dp(n, vector<int>(n, 0));
    auto run = [](char alice, char bob, int next_state) {
        if (alice < bob) return 1;
        else if (alice > bob) return 1;
        else return next_state;
    };
    for (int l = 0; l + 1 < n; l++) {
        dp[l][l+1] = (str[l] == str[l+1]? 0 : 1);
    }
    for (int len = 4; len <= n; len += 2) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            // strategy: left left
            int s_ll = run(str[l], str[l+1], dp[l+2][r]);
            // strategy: left right
            int s_lr = run(str[l], str[r], dp[l+1][r-1]);
            // strategy: right left
            int s_rl = run(str[r], str[l], dp[l+1][r-1]);
            // strategy: right right
            int s_rr = run(str[r], str[r-1], dp[l][r-2]);
            // update dp
            if (s_ll == 1 && s_lr == 1) {
                dp[l][r] = 1;
            } else if (s_rl == 1 && s_rr == 1) {
                dp[l][r] = 1;
            } else if (s_ll == 2 && s_lr == 2 && s_rl == 2 && s_rr == 2) {
                dp[l][r] = 2;
            } else {
                dp[l][r] = 0;
            }
        }
    }
    // answer
    if (dp[0][n-1] == 0) cout << "Draw\n";
    else if (dp[0][n-1] == 1) cout << "Alice\n";
    else cout << "Bob\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

