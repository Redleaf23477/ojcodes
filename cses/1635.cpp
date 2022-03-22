#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    constexpr int INF = 2 * 1e6;
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (auto & x : arr) cin >> x;
    vector<LL> dp(x+1, 0);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (auto x : arr) {
            if (i - x >= 0) dp[i] += dp[i-x];
        }
        dp[i] %= MOD;
    }
    cout << dp[x] << "\n";
}