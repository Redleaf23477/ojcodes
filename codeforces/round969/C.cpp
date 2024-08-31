#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    size_t n; cin >> n;
    LL a, b; cin >> a >> b;
    LL g = gcd(a, b);
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    for (auto &x : arr) x %= g;
    sort(arr.begin(), arr.end());

    LL ans = arr[n - 1] - arr[0];
    for (size_t i = 0; i + 1 < n; i++) {
        arr[i] += g;
        ans = min(ans, arr[i] - arr[i + 1]);
    }
    arr[n - 1] += g;
    ans = min(ans, arr[n - 1] - arr[0]);

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

