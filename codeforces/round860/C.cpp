#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<pair<LL,LL>> arr(n);
    for (auto &[a, b] : arr) cin >> a >> b;
    int ans = 1;
    LL ga = arr[0].first, lb = arr[0].second;
    for (int i = 1; i < n; i++) {
        auto [a, b] = arr[i];
        LL new_lcm = lcm(lb, b);
        LL d_old = new_lcm / lb;
        LL d_new = new_lcm / b;
        if (ga % d_old == 0 && a % d_new == 0) {
            lb = new_lcm;
            ga = gcd(ga / d_old, a / d_new);
        } else {
            ga = a, lb = b, ans++;
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



