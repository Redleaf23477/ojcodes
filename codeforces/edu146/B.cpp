#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL run(LL a, LL b) {
    LL ans = a + b;
    for (LL f = 1; f <= a; f++) {
        ans = min(ans, f - 1 + (a + f - 1) / f + (b + f - 1) / f);
        f = a / (a / f);
        ans = min(ans, f - 1 + (a + f - 1) / f + (b + f - 1) / f);
    }
    return ans;
}
 
void solve() {
    LL a, b; cin >> a >> b;
    cout << min(run(a, b), run(b, a)) << "\n";
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
