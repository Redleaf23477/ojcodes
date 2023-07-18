#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    LL ans = *max_element(arr.begin(), arr.end());

    for (int base = 0; base <= 1; base++) {
        LL sum = 0, cnt = 0;
        for (int i = base; i < n; i += 2) {
            if (arr[i] > 0) sum += arr[i], cnt++;
        }
        if (cnt > 0) ans = max(ans, sum);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    //    int T = 1;
    while (T--) {
        solve();
    }
}



