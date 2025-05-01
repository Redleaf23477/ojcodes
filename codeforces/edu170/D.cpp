#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    // dp[i][j]: consider first i 0s, choose j for strength: #pass
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
    dp[0][0] = 0;

    int zeros = 0;
    vector<int> buff(m + 2, 0);

    auto apply = [&]() {
        partial_sum(buff.begin(), buff.end(), buff.begin());
        for (int i = 0; i <= zeros; i++) {
            dp[zeros][i] += buff[i];
        }
        fill(buff.begin(), buff.end(), 0);
    };

    for (int i = 0; i < n; i++) {
        if (i == 0 && arr[0] != 0) continue;

        int x = arr[i];
        if (x == 0) {
            // dp[z] -> dp[z + 1]
            apply();

            zeros++;
            dp[zeros][0] = dp[zeros - 1][0];
            for (int str = 1; str <= zeros; str++) {
                dp[zeros][str] = max(dp[zeros - 1][str], dp[zeros - 1][str - 1]);
            }
        } else if (x > 0) {
            // intel >= x --> str <= zeros - x
            /*
               for (int i = 0; i <= zeros - x; i++) {
               dp[zeros][i] += 1;
               }
               */
            if (0 <= zeros - x) {
                buff[0] += 1;
                buff[zeros - x + 1] -= 1;
            }
        } else {
            x = -x;
            // str >= x
            /*
               for (int i = x; i <= zeros; i++) {
               dp[zeros][i] += 1;
               }
               */
            if (x <= zeros) {
                buff[x] += 1;
                buff[zeros + 1] -= 1;
            }
        }
    }

    apply();
    cout << *max_element(dp[zeros].begin(), dp[zeros].end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

