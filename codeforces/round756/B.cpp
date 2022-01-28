#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool good(LL team, LL a, LL b) {
    if (a < team || b < team) {
        return false;
    }
    a -= team, b -= team;
    a += b;
    return a / 2 >= team;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        LL a, b; cin >> a >> b;
        LL l = 0, r = (a+b)/4, mid, ans = 0;
        while (l <= r) {
            mid = (l + r)/2;
            if (good(mid, a, b)) {
                ans = mid, l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        cout << ans << "\n";
    }
}

