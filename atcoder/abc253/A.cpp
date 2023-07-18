#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    if (a > c) swap(a, c);
    if (a <= b && b <= c) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



