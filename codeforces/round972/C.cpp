#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> arr(n);
    for (auto &x : arr) cin >> x;
    string narek = "narek";

    // dp[i][j] = I am at arr[i], ending with narek[j]
    const int INF = n * m;
    vector<vector<int>> dp(2, vector<int>(narek.size(), -INF));
    dp[1][narek.size() - 1] = 0;

    int ans = 0;

    for (int i = 0; i < n; i++) {
        auto &dp_now = dp[i % 2];
        auto &dp_prev = dp[1 - i % 2];

        // I don't use arr[i]
        dp_now = dp_prev;

        // I use arr[i]
        for (int j = 0; j < (int)narek.size(); j++) {
            // push dp[i - 1][j] to dp[i][something]
            if (dp_prev[j] == -INF) continue;
            int score = dp_prev[j];
            int curr = j, next = (j + 1) % narek.size();
            for (auto ch : arr[i]) {
                if (ch == narek[next]) {
                    curr = next, next = (next + 1) % narek.size();
                    if (curr + 1 == narek.size()) {
                        score += 5;
                    }
                } else if (find(narek.begin(), narek.end(), ch) != narek.end()) {
                    score -= 1;
                }
            }
            dp_now[curr] = max(dp_now[curr], score);
            ans = max(ans, score - (curr + 1 == narek.size()? 0 : curr + 1));
        }

        /*
        cerr << "i = " << i << ": ";
        for (auto x : dp_now) cerr << x << " ";
        cerr << endl;
        */
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

