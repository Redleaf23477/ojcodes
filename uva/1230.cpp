#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL fastpw(LL x, LL y, LL n) {
    x %= n;
    LL ans = (x%n != 0);
    while (y > 0) {
        if (y % 2 == 1) ans = ans * x % n;
        x = x * x % n;
        y /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        LL x, y, n; cin >> x >> y >> n;
        cout << fastpw(x, y, n) << "\n";
    }
    cin >> T;  // 0
}

