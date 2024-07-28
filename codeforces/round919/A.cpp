#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    int lb = 1, ub = 1'000'000'000;
    set<int> bad;
    while (n--) {
        int cmd, x; cin >> cmd >> x;
        if (cmd == 1) lb = max(lb, x);
        else if (cmd == 2) ub = min(ub, x);
        else bad.insert(x);
    }
    int ans = max(0, ub - lb + 1);
    for (auto x : bad) {
        if (lb <= x && x <= ub) {
            ans -= 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

