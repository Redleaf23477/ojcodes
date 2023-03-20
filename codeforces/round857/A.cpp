#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos += (x > 0);
        neg += (x < 0);
    }

    int ans = 0;
    for (int i = 0; i < pos; i++) {
        cout << ++ans << " ";
    }
    for (int i = 0; i < neg; i++) {
        cout << --ans << " ";
    }
    cout << "\n";

    for (int i = 0; i < neg; i++) {
        cout << 1 << " " << 0 << " ";
    }
    ans = 0;
    for (int i = neg; i < pos; i++) {
        cout << ++ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



