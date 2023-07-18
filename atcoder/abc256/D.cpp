#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<pair<int,int>> arr(n);
    for (auto &[l, r] : arr) cin >> l >> r;
    sort(arr.begin(), arr.end());
    arr.emplace_back(1e9, 1e9);

    vector<pair<int,int>> ans;
    int L = arr[0].first, R = arr[0].second;
    for (auto [l, r] : arr) {
        if (l > R) {
            ans.emplace_back(L, R);
            L = l, R = r;
        } else {
            R = max(R, r);
        }
    }

    for (auto [l, r] : ans) {
        cout << l << " " << r << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



