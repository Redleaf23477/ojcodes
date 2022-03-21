#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<int> tmp(1, 0), dp(n, 1);
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(tmp.begin(), tmp.end(), arr[i]);
        dp[i] = it - tmp.begin();
        if (it == tmp.end()) {
            tmp.emplace_back(arr[i]);
        } else {
            tmp[dp[i]] = min(tmp[dp[i]], arr[i]);
        }
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
}

