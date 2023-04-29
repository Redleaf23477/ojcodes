#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    multiset<LL> neg, zero, pos;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        if (x < 0) neg.insert(x);
        else if (x == 0) zero.insert(x);
        else pos.insert(x);
    }
    LL ans = -1e18 - 3;
    // neg neg
    if (neg.size() >= 2) {
        auto it = neg.begin();
        auto jt = it; jt++;
        ans = max(ans, (*it) * (*jt));
    }
    // pos pos
    if (pos.size() >= 2) {
        auto it = pos.rbegin();
        auto jt = it; jt++;
        ans = max(ans, (*it) * (*jt));
    }
    // zero
    if (zero.size() > 0) {
        ans = max(ans, 0ll);
    }
    // pos neg
    if (neg.size() > 0 && pos.size() > 0) {
        ans = max(ans, (*pos.begin()) * (*neg.begin()));
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



