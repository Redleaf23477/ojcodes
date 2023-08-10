#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

LL pick(int num, vector<LL> const &arr, int N) {
    vector dp(N, vector<vector<LL>>(num + 1, vector<LL>(num, 0)));
    dp[0][0][0] = 1, dp[0][1][arr[0] % num] = 1;
    for (int i = 1; i < N; i++) {
        dp[i][0][0] = 1;
        for (int j = 1; j <= num; j++) {
            for (int k = 0; k < num; k++) {
                dp[i][j][k] = (dp[i-1][j][k] + dp[i-1][j-1][(k - arr[i] % num + num) % num]) % MOD;
            }
        }
    }
    return dp[N - 1][num][0];
}

void solve() {
    int N; cin >> N;
    vector<LL> arr(N);
    for (auto &x : arr) cin >> x;
    LL ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = (ans + pick(i, arr, N)) % MOD;
    }
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



