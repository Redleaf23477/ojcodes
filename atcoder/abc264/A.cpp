#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int l, r; cin >> l >> r;
    cout << string("atcoder").substr(l - 1, r - l + 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



