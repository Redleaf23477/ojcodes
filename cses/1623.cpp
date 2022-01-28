#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    LL ans = accumulate(arr.begin(), arr.end(), 0ll);
    for (int m = 0; m < (1<<n); m++) {
        vector<LL> sum(2, 0);
        for (int i = 0; i < n; i++) {
            sum[(m >> i) & 1] += arr[i];
        }
        ans = min(ans, abs(sum[0] - sum[1]));
    }
    cout << ans << "\n";
}

