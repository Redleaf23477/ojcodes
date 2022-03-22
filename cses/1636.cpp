#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (auto & x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    vector<LL> dp(x+1, 0);
    dp[0] = 1;
    for (auto c : arr) {
        for (int i = 1; i <= x; i++) {
            if (i - c >= 0) dp[i] = (dp[i] + dp[i-c]) % MOD;
        }
    }
    cout << dp[x] << "\n";
}