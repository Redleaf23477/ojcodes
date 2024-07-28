#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    for (int i = 0, j = n - 1; j >= 0 && i < x; i++, j--) {
        arr[j] *= -1;
    }
    LL acc = accumulate(arr.begin(), arr.end(), 0ll);
    LL ans = acc;
    for (int i = 0, j = n - 1; j >= 0 && i < k; i++, j--) {
        acc -= arr[j];
        if (j - x >= 0) {
            acc -= 2 * arr[j - x];
            arr[j - x] *= -1;
        }
        ans = max(ans, acc);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

