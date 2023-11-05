#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL a, b; cin >> a >> b;
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    LL ans = b - 1;
    for (auto x : arr) {
        ans += min(a - 1, x);
    }
    cout << ans + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
}

