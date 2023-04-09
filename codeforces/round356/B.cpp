#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, a; cin >> n >> a; a--;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int ans = (arr[a] == 1);
    for (int d = 1; d < n; d++) {
        int l = a - d, r = a + d;
        if (0 <= l && r < n) {
            ans += 2 * (arr[l] + arr[r] == 2);
        } else if (l >= 0) {
            ans += (arr[l] == 1);
        } else if (r < n) {
            ans += (arr[r] == 1);
        } else {
            break;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



