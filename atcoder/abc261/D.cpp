#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL INF = 1e18;

void solve() {
    int N, M; cin >> N >> M;
    vector<LL> prize(N);
    for (auto &x : prize) cin >> x;
    vector<LL> bonus(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int c, y; cin >> c >> y;
        bonus[c] = y;
    }

    // dp[i-th toss][counter] = money
    vector<vector<LL>> dp(N, vector<LL>(N + 1, -INF));
    dp[0][0] = bonus[0], dp[0][1] = prize[0] + bonus[1];
    for (int i = 1; i < N; i++) {
        // tail
        dp[i][0] = *max_element(dp[i-1].begin(), dp[i-1].end()) + bonus[0];
        // head
        for (int c = 1; c <= N; c++) {
            dp[i][c] = max(dp[i][c], dp[i-1][c-1] + prize[i] + bonus[c]);
        }
    }
    cout << *max_element(dp[N-1].begin(), dp[N-1].end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



