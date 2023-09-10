#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL INF = 1e18;

void solve() {
    int N; cin >> N;
    vector<tuple<int,int,LL>> arr(N + 1);
    arr[0] = make_tuple(0, 0, 0);
    for (int i = 1; i <= N; i++) {
        auto &[t, x, a] = arr[i];
        cin >> t >> x >> a;
    }

    // dp[i-th snuke][takahashi pos]
    vector<vector<LL>> dp(N + 1, vector<LL>(5, -INF));
    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        auto [t, x, a] = arr[i];
        int t_prev = get<0>(arr[i - 1]);
        int t_move = t - t_prev;
        for (int p_now = 0; p_now < 5; p_now++) {
            for (int p_prev = 0; p_prev < 5; p_prev++) {
                if (abs(p_now - p_prev) > t_move) continue;
                dp[i][p_now] = max(dp[i][p_now], dp[i - 1][p_prev]);
            }
        }
        if (dp[i][x] != -INF) {
            dp[i][x] += a;
        }
    }
    cout << *max_element(dp[N].begin(), dp[N].end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}