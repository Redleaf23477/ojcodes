#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

tuple<LL,LL> non_2_fac(LL x) {
    LL cnt = 1;
    while (x > 1) {
        if (x % 2 == 1) return make_tuple(cnt, x);
        x /= 2;
        cnt *= 2;
    }
    return make_tuple(cnt, 1);
}

void solve() {
    LL x; cin >> x;
    auto [a, b] = non_2_fac(2 * x);
    if (a > b) swap(a, b);
    if (a == 1) cout << "-1\n";
    else cout << a << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

