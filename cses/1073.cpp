#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<int> tmp(1, 0);
    vector<int> dp(n+1, 0);
    for (int i = 1; i <= n; i++) {
        auto it = upper_bound(tmp.begin(), tmp.end(), arr[i]); it--;
        int h = it - tmp.begin();
        dp[i] = h + 1;
        if (tmp.size() == dp[i]) tmp.emplace_back(arr[i]);
        else {
            tmp[dp[i]] = min(tmp[dp[i]], arr[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}

