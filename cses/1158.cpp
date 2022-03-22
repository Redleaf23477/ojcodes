#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> weight(n), val(n);
    for (auto &w : weight) cin >> w;
    for (auto &v : val) cin >> v;
    vector<vector<int>> dp(2, vector<int>(x+1, 0));
    for (int i = 0; i < n; i++) {
        for (int w = 1; w <= x; w++) {
            if (w >= weight[i]) {
                dp[i%2][w] = max(dp[1-i%2][w], dp[1-i%2][w-weight[i]] + val[i]);
            } else {
                dp[i%2][w] = dp[1-i%2][w];
            }
        }
    }
    cout << dp[1-n%2][x] << "\n";
}