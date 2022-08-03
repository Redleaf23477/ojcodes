#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    LL x; cin >> x;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    LL ans = 0;
    for (int i = 1; i < n; i++) {
        ans += abs(arr[i] - arr[i-1]);
    }
    auto run = [&](LL num) {
        LL tmp = min(abs(num - arr[0]), abs(num - arr[n-1]));
        for (int i = 0; i < n-1; i++) {
            tmp = min(tmp, abs(num - arr[i]) + abs(num - arr[i+1]) - abs(arr[i] - arr[i+1]));
        }
        return tmp;
    };
    if (1 < *min_element(arr.begin(), arr.end())) {
        ans += run(1);
    }
    if (x > *max_element(arr.begin(), arr.end())) {
        ans += run(x);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

