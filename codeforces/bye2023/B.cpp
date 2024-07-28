#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL a, b; cin >> a >> b;
    if (a == 1) cout << b * b << "\n";
    else {
        LL l = lcm(a, b);
        if (l == b) cout << b * (b / a) << "\n";
        else cout << l << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

