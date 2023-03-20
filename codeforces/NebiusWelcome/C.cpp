#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL n, x, p; cin >> n >> x >> p;
    for (LL fwd = 1, iam = 0; fwd <= min(p, 3*n); fwd++) {
        iam = (iam - fwd % n + n) % n;
//        cerr << "iam = " << iam << endl;
        if (iam == x) {
            cout << "Yes\n"; return;
        }
    }
    cout << "No\n"; return;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



