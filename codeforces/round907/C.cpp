#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    LL ans = 0, x = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (l == r) {
            if (x > 0) {
                arr[l] -= x, ans++;
                ans += (arr[l] + 1) / 2;
            } else {
                ans += (arr[l] + 1) / 2;
                if (arr[l] > 1) ans++;
            }
            break;
        } else if (x + arr[l] >= arr[r]) {
            LL delta = arr[r] - x;
            arr[l] -= delta, x = 0, r--, ans += delta + 1;
        } else {
            ans += arr[l], x += arr[l], l++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

