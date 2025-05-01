#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int a, b; cin >> a >> b;
    b %= 2;
    if (b == 0) {
        if (a % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        if (a < 2) {
            cout << "NO\n";
        } else {
            a -= 2;
            if (a % 2 == 0) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

