#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n, k; cin >> n >> k;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    if (n == 1) {
        if (k - 1 < arr[0]) cout << k - 1 << "\n";
        else cout << k << "\n";
        return;
    }

    LL g = arr[0];
    for (auto &x : arr) g = gcd(g, x);

    k -= 1;

    if (g == 1) {
        cout << n + k << "\n";
    } else {
        LL gap = min(n, k / (g - 1));
        k -= gap * (g - 1);
        if (gap == n) {
            cout << g * gap + k << "\n";
        } else if (k != 0) {
            cout << g * gap + k + 1 << "\n";
        } else {
            cout << g * gap + k + 1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

