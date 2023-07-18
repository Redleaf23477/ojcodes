#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL INF = 1e18;

void solve() {
    int N; cin >> N;
    vector<LL> A(N);
    for (auto &x : A) cin >> x;

    // dp[i][is_i_covered][is_0_covered]
    vector<vector<vector<LL>>> dp(N, vector<vector<LL>>(2, vector<LL>(2, INF)));
    dp[1][true][true] = A[0];
    dp[1][false][false] = 0;
    for (int i = 2; i < N; i++) {
        for (int zero : {false, true}) {
            // pick A[i-1]
            dp[i][true][zero] = min(dp[i-1][false][zero], dp[i-1][true][zero]) + A[i-1];
            // don't pick A[i-1]
            dp[i][false][zero] = dp[i-1][true][zero];
        }
    }

    LL no_last = dp[N-1][true][true];
    LL pick_last = min({dp[N-1][true][false], dp[N-1][false][true], dp[N-1][false][false]}) + A.back();

    cout << min(no_last, pick_last) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



