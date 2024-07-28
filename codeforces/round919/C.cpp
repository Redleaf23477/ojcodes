#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        if (n % k != 0) continue;
        int g = 0;
        for (int i = 0; i < k; i++) {
            for (int j = i; j < n; j += k) {
                g = gcd(g, abs(arr[i] - arr[j]));
            }
        }
        ans += (g != 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

