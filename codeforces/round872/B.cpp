#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL n, m; cin >> n >> m;
    if (n > m) swap(n, m);
    // now n < m
    LL sz = n * m;
    vector<LL> arr(sz);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());
    LL ans = -1e18;

    // case 1
    vector<LL> case1 {arr[0], arr[1], arr.back()};
    do {
        LL a = case1[0], b = case1[1], c = case1[2];
        ans = max(ans, (a - c) * (n-1) + (a - b) * (m-1) + (a - min(b, c)) * (n-1) * (m-1));
    } while (next_permutation(case1.begin(), case1.end()));
    vector<LL> case2 {arr[0], arr.end()[-2], arr.back()};
    do {
        LL a = case2[0], b = case2[1], c = case2[2];
        ans = max(ans, (c - a) * (n-1) + (b - a) * (m-1) + (max(b, c) - a) * (n-1) * (m-1));
    } while (next_permutation(case2.begin(), case2.end()));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



