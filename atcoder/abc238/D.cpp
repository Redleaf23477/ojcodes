#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL a, s; cin >> a >> s;
    LL d = s - 2 * a;
    if (d < 0) {
        cout << "No\n";
    } else if (d & a) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

