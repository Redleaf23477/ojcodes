#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<int> bit(31, 0);
    for (auto x : arr) {
        for (int i = 0; i < 31; i++) {
            if ((x >> i) & 1) bit[i] += 1;
        }
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int need = n - bit[i];
        if (k >= need) {
            ans |= (1 << i);
            k -= need;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

