#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;

    if (m == 1) {
        if (*max_element(arr.begin(), arr.end()) != *min_element(arr.begin(), arr.end())) {
            cout << -1 << "\n";
        } else {
            cout << 0 << "\n";
        }
        return;
    }

    int mn = *min_element(arr.begin(), arr.end());
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (arr[i] == mn) pos.emplace_back(i);
    }

    int ans = 0, r = -n;
    for (int i = 0; i < n; i++) {
        if (arr[i] != mn && r < i) {
            ans += 1;
            auto it = upper_bound(pos.begin(), pos.end(), i);
            if (it != pos.end() && *it - i <= m - 1) {
                r = i + m - 1;
            } else {
                r = i + m - 2;
            }
        }
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

