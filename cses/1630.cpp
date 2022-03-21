#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<int,int>;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<T> arr(n);
    for (auto &[l, r] : arr) cin >> l >> r;
    sort(arr.begin(), arr.end());

    LL ans = 0, t = 0;
    for (int i = 0; i < n; i++) {
        auto [l, r] = arr[i];
        t += l, ans += r - t;
    }
    cout << ans << "\n";
}

