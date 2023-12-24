#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int mylg2(int x) {
    int ans = 0;
    while (x) ans++, x /= 2;
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int mx = *max_element(arr.begin(), arr.end());
    int mn = *min_element(arr.begin(), arr.end());

    vector<int> ans;
    while (mx != mn) {
        if (mn % 2 == 1) {
            ans.emplace_back(1);
            mn = (mn + 1) / 2, mx = (mx + 1) / 2;
        } else {
            ans.emplace_back(0);
            mn /= 2, mx /= 2;
        }
    }

    cout << ans.size() << "\n";
    if ((int)ans.size() <= n) {
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

