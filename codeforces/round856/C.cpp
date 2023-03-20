#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    for (int i = 0; i < n; i++) {
        int l = 0, r = i, mid, ans = i;
        while (l <= r) {
            mid = (l + r) / 2;
            if (arr[mid] >= i - mid + 1) {
                ans = mid, r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << i - ans + 1 << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



