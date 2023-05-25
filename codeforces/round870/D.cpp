#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    multiset<LL> L, R;
    L.insert(arr[0] + 0);
    for (int i = 1; i < n; i++) R.insert(arr[i] - i);
    LL ans = -1e18;
    for (int i = 1; i < n-1; i++) {
        // remove from R
        R.erase(R.find(arr[i] - i));
        // calculate candidate
        ans = max(ans, arr[i] + *(L.rbegin()) + *(R.rbegin()));
        // insert to L
        L.insert(arr[i] + i);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



