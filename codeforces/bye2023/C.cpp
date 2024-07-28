#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    LL sum = 0;
    int odd = 0, even = 0;
    for (auto x : arr) {
        sum += x;
        if (x % 2 == 1) odd++;
        else even++;

        if (odd + even == 1) {
            cout << sum << " ";
        } else {
            cout << sum - (odd / 3) - (odd % 3 == 1) << " ";
        }
    }

    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

