#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        LL a, b; cin >> a >> b;
        // a = 2*x +   y
        // b =   x + 2*y
        // (a+b)/3 = x + y, where x, y is int
        // x = a - (a+b)/3
        // y = b - (a+b)/3
        LL x = a - (a + b) / 3;
        LL y = b - (a + b) / 3;

        if ((a + b) % 3 != 0 || x < 0 || y < 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}

