#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL INF = 1e18;

// Observations:
// 1) Let ai = ai - i so that it become non-strickly increasing
// 2) There exist optimal solution using only numbers in (a1, ..., an)


vector<LL> make_unique(const vector<LL> &arr) {
    vector<LL> ans(arr);
    sort(ans.begin(), ans.end());
    auto it = unique(ans.begin(), ans.end());
    ans.erase(it, ans.end());
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<LL> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i]; arr[i] -= i;
    }
    vector<LL> val = make_unique(arr);
    int m = val.size();

    vector<vector<LL>> dp(n+1, vector<LL>(m, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            dp[i][j] = dp[i-1][j] + abs(arr[i-1] - val[j]);
        }
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m-1] << "\n";
}

