#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    constexpr int INF = 2 * 1e6;
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (auto & x : arr) cin >> x;
    vector<int> dp(x+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (auto x : arr) {
            if (i - x >= 0) dp[i] = min(dp[i], dp[i-x]+1);
        }
    }
    if (dp[x] == INF) cout << -1 << "\n";
    else cout << dp[x] << "\n";
}