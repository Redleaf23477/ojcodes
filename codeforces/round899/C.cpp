#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int INF = 1e9;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<LL> mx_suff(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        mx_suff[i] = max(mx_suff[i + 1], arr[i] + mx_suff[i + 1]);
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        // if I first take arr[i]
        if (i % 2 == 0) ans = max(ans, arr[i] + mx_suff[i + 1]);
        else ans = max(ans, mx_suff[i + 1]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

