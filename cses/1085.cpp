#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool ok(LL sum, const int k, const vector<LL> &arr) {
    int ans = 1;
    LL s = 0;
    for (auto x : arr) {
        if (sum < x) return false;
        if (s + x <= sum) s += x;
        else ans += 1, s = x;
    }
    return ans <= k;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, k; cin >> n >> k;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    LL low = 0, high = 1e18, mid, ans = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (ok(mid, k, arr)) high = mid - 1, ans = mid;
        else low = mid + 1;
    }
    cout << ans << "\n";
}

