#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL Q; cin >> Q;
    multiset<LL> A;
    while (Q--) {
        LL op; cin >> op;
        if (op == 1) {
            LL x; cin >> x;
            A.insert(x);
        } else if (op == 2) {
            LL x, k; cin >> x >> k;
            auto it = A.upper_bound(x);
            LL ans = 0;
            while (k--) {
                if (it == A.begin()) {
                    ans = -1; break;
                }
                it--;
            }
            if (ans != -1) ans = *it;
            cout << ans << "\n";
        } else {
            LL x, k; cin >> x >> k; k--;
            auto it = A.lower_bound(x);
            LL ans = 0;
            while (k--) {
                if (it == A.end()) {
                    ans = -1; break;
                }
                it++;
            }
            if (ans != -1) {
                ans = (it == A.end()? -1 : *it);
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL T = 1;
    while (T--) {
        solve();
    }
}



