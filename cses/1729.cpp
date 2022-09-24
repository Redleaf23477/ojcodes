#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> arr(k);
    for (auto &x : arr) cin >> x;

    vector<bool> dp(n + 1, false);
    for (int i = 1; i <= n; i++) {
        for (auto p : arr) {
            if (i - p < 0) continue;
            if (dp[i - p] == false) dp[i] = true;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << (dp[i]? 'W' : 'L');
    }
    cout << "\n";
}

