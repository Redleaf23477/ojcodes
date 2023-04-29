#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<vector<LL>> dp(N, vector<LL>(10, 0));
    for (int num = 1; num <= 9; num++) dp[0][num] = 1;
    for (int i = 1; i < N; i++) {
        for (int num = 1; num <= 9; num++) {
            for (int d = -1; d <= 1; d++) {
                int num2 = num + d;
                if (0 < num2 && num2 <= 9) {
                    dp[i][num] = (dp[i][num] + dp[i-1][num2]) % MOD;
                }
            }
        }
    }
    LL ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += dp[N-1][i];
    }
    cout << ans % MOD << "\n";
}



