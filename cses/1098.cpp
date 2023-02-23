#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    int nim = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        nim ^= (x % 4);
    }
    cout << (nim != 0? "first\n" : "second\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

