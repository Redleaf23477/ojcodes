#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

void solve() {
    int N, M; cin >> N >> M;
    vector<pair<LL,LL>> vec(3);
    for (auto &[x, y] : vec) cin >> x >> y;

    set<pair<LL,LL>> bad_point;
    for (int i = 0; i < M; i++) {
        LL x, y; cin >> x >> y;
        bad_point.insert(make_pair(x, y));
    }
    auto bad = [&](int i, int j, int k) {
        LL x = i * vec[0].first + j * vec[1].first + k * vec[2].first;
        LL y = i * vec[0].second + j * vec[1].second + k * vec[2].second;
        return bad_point.count(make_pair(x, y)) != 0;
    };

    // dp[i][j][k] = num of path using i vec[0], j vec[1], k vec[2]
    vector dp(N + 1, vector<vector<LL>>(N + 1, vector<LL>(N + 1, 0)));
    dp[0][0][0] = 1;
    for (int cnt = 1; cnt <= N; cnt++) {
        for (int i = 0; i <= cnt; i++) {
            for (int j = 0; i + j <= cnt; j++) {
                int k = cnt - i - j;
                if (bad(i, j, k)) continue;
                if (i - 1 >= 0) dp[i][j][k] += dp[i - 1][j][k];
                if (j - 1 >= 0) dp[i][j][k] += dp[i][j - 1][k];
                if (k - 1 >= 0) dp[i][j][k] += dp[i][j][k - 1];
                dp[i][j][k] %= MOD;
            }
        }
    }

    LL ans = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; i + j <= N; j++) {
            int k = N - i - j;
            ans += dp[i][j][k];
        }
    }
    ans %= MOD;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



