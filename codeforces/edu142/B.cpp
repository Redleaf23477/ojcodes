#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int ans = 0;
    int alice = 0, bob = 0;
    ans += a, alice += a, bob += a;
    if (a > 0) {
        int tmp = min(b, c);
        ans += 2 * tmp;
        b -= tmp;
        c -= tmp;
    }
    if (b > 0) {
        int tmp = min(bob, b);
        ans += tmp;
        b -= tmp;
        alice += tmp;
        bob -= tmp;
    }
    if (c > 0) {
        int tmp = min(alice, c);
        ans += tmp;
        c -= tmp;
        alice -= tmp;
        bob += tmp;
    }
    if (d > 0) {
        int tmp = min({alice, bob, d});
        ans += tmp;
        d -= tmp;
        alice -= tmp;
        bob -= tmp;
    }
    if (b + c + d > 0) ans++;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

