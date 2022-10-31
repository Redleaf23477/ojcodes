#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<int> dp(1 << n, -48763);
    dp[0] = 0;
    for (int m = 1; m < (1 << n); m++) {
        for (int i = 0; i < n; i++) {
            if ((m >> i) & 1) {
                int first = arr[i];
                int last = dp[m ^ (1 << i)];
                dp[m] = max(dp[m], first - last);
            }
        }
    }
    int sum = accumulate(arr.begin(), arr.end(), 0);
    int delta = dp[(1 << n) - 1];
    int alice = (sum - delta) / 2 + delta;
    int bob = sum - alice;
    cout << alice << " " << bob << "\n";
}

