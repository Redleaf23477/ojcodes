#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    int rem = n % 3;
    int a, b, c;
    if (rem == 2 || rem == 1) {
        a = 1, b = 2, c = n - 3;
    } else {
        a = 1, b = 4, c = n - 5;
    }
    if (a != c && b != c && c > 0) {
        cout << "YES\n";
        cout << a << " " << b << " " << c << "\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

