#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL n, k, d, w; cin >> n >> k >> d >> w;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    auto good = [&](int pack) {
        int tim = -1, rem = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > tim || rem == 0) {
                // new pack
                if (--pack < 0) {
                    return false;
                }
                tim = arr[i] + w + d;
                rem = k;
            }
            rem--;
        }
        return true;
    };

    int low = 1, high = n, mid, ans = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (good(mid)) {
            ans = mid, high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



