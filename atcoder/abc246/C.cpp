#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k, x; cin >> n >> k >> x;
    vector<int> arr(n);
    for (auto &y : arr) cin >> y;
    for (auto &y : arr) {
        int q = y / x;
        int use = min(q, k);
        y -= use * x;
        k -= use;
    }
    sort(arr.begin(), arr.end(), greater<int>());
    for (auto &y : arr) {
        if (k > 0) y = 0, k--;
    }
    cout << accumulate(arr.begin(), arr.end(), 0ll) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



