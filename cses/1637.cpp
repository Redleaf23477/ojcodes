#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<int> find_digits(int i) {
    vector<int> ans;
    while (i > 0) {
        ans.emplace_back(i % 10);
        i /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    constexpr int INF = 2 * 1e6;
    vector<int> dp(n+1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> digits = find_digits(i);
        for (auto d : digits) {
            dp[i] = min(dp[i], dp[i-d] + 1);
        }
    }
    cout << dp[n] << "\n";
}