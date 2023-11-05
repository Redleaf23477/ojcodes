#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9 + 7;
constexpr LL E18 = (LL)1e18 + 2;

/*
using LL = __int128;
istream& operator >> (istream &in, LL &x) {
    long long y; in >> y;
    x = y;
    return in;
}

ostream& operator << (ostream &out, LL &x) {
    long long y = x;
    out << y;
    return out;
}
*/

LL pw(LL x, LL p) {
    LL ans = 1;
    while (p--) {
        if (ans > E18 / x) return E18;
        ans *= x;
    }
    return ans;
}

LL bs_log(LL base, LL x) {
    int log = 0;
    while (x > 0) {
        log += 1, x /= base;
    }
    return log - 1;
}

LL f(LL x) { return bs_log(2, x); }
LL g(LL base, LL x) { return bs_log(base, x); }

void solve() {
    LL l, r; cin >> l >> r; r += 1;
    LL ans = 0;
    while (l < r) {
        LL fl = f(l);
        LL l2 = pw(2, fl + 1);
        // cerr << "l = " << l << ", f(l) = " << fl << ", l2 = " << l2 << endl;
        while (l < l2 && l < r) {
            LL gl = g(fl, l);
            LL l3 = pw(fl, gl + 1);
            LL stop = min({r, l2, l3});
            // cerr << "gl = " << gl << ", l3 = " << l3 << ", stop = " << stop << endl;
            ans = (ans + (stop - l) % MOD * gl) % MOD;
            l = stop;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

