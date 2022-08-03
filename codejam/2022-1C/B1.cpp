#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

// B1 only

void solve() {
    LL n, k; cin >> n >> k; // k == 1
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    LL A = 0, B = 0;
    for (auto &x : arr) {
        A += x;
        B += x * x;
    }
    LL up = B - A * A;
    LL down = 2 * A;
    if (A == 0 && B == 0) {
        cout << 7122 << "\n";
    } else if (down == 0 || up % down != 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << up / down << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

