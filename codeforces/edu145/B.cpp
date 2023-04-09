#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL s1(LL n) {
    LL low = 0, high = 1.5 * 1e9, ans = 0, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        LL black = 1 + (1 + mid) * mid / 2 * 8;
        if (black >= n) {
            ans = mid, high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans * 2;
}

LL s2(LL n) {
    LL low = 1, high = 1.5 * 1e9, ans = 0, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        LL white = (1 + 2 * mid - 1) * mid / 2 * 4;
        if (white >= n) {
            ans = mid, high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return 1 + (ans - 1) * 2;
}

/*
LL s1(LL n) {
    LL low = 0, high = 1.5 * 1e9, ans = 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        LL len = 1 + 2 * mid;
        LL black = len * len / 2 + 1;
        if (black >= n) {
            ans = len, high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans / 2 * 2;
}

LL s2(LL n) {
    LL low = 1, high = 1.5 * 1e9, ans = 3, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        LL len = 1 + 2 * mid;
        LL black = len * len / 2 + 1;
        LL white = len * len - black;
        if (white >= n) {
            ans = len, high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans / 2 * 2 - 1;
}
*/

void solve() {
    LL n; cin >> n;
    cout << min(s1(n), s2(n)) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



