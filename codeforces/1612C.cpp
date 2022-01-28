#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool good(LL lv, LL k, LL x) {
    LL sum = 0;
    if (lv <= k) {
        sum += (1 + lv) * lv / 2;
    } else {
        sum += (1 + k) * k / 2;
        lv -= k;
        sum += (k-1 + k-lv) * lv / 2;
    }
    return sum >= x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        LL k, x; cin >> k >> x;
        LL l = 1, r = k+k-1, mid, ans = r;
        while (l <= r) {
            mid = (l + r) / 2;
            if (good(mid, k, x)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        cout << ans << "\n";
    }
}

