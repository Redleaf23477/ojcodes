#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    
    LL ans = 0;
    // strategy V
    for (int i = 0; i < n-2; i++) {
        LL w1 = arr.back();
        LL w2 = arr[i];
        LL w3 = arr[i+1];
        ans = max(ans, w1 - w2 + w3 - w2);
    }
    // strategy ^
    for (int i = 2; i < n; i++) {
        LL w1 = arr.front();
        LL w2 = arr[i];
        LL w3 = arr[i-1];
        ans = max(ans, w2 - w1 + w2 - w3);
    }
    // strategy /
    ans = max(ans, arr.back() - arr.front());
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

