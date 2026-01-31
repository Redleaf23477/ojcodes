#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n, k; cin >> n >> k;

    k -= n;

    if (k <= 0) {
        cout << 0 << "\n";
        return;
    }

    auto good = [n, k](LL mid) {
        LL eat = ((n + 1) + (n + mid)) * mid / 2;
        return eat >= k;
    };

    LL low = 1, high = k, mid, ans = -1;
    while (low <= high) {
        mid = std::midpoint(low, high);
        if (good(mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

