#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    LL x; cin >> x;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    partial_sum(arr.begin(), arr.end(), arr.begin());

    LL ans = 0;
    LL day = 0;
    for (int i = n-1; i >= 0; i--) {
        LL s = arr[i] + day * (i+1);
        if (s > x) continue;
        // I can buy them for the next d days
        LL d = (x - s) / (i+1) + 1;
        ans += d * (i+1);
        day += d;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

