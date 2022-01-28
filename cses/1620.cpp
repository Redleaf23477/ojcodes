#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool good(LL tim, LL tot, vector<LL> &arr) {
    for (auto x : arr) {
        tot -= tim / x;
        if (tot <= 0) break;
    }
    return tot <= 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    LL t; cin >> t;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    LL l = 0, r = 1e18, mid, ans = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (good(mid, t, arr)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << "\n";
}

