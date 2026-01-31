#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n, t; cin >> n >> t;
    vector<LL> a(n);
    for (auto &x : a) cin >> x;

    LL ans = 0;
    LL closed = 0;
    for (auto x : a) {
        if (x < closed) continue;
        ans += x - closed;
        closed = x + 100;
    }
    if (t >= closed) {
        ans += t - closed;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

