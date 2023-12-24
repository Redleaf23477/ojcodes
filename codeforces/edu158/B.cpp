#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    LL ans = arr[0] - 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            ans += arr[i] - arr[i - 1];
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

