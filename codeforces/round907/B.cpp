#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int lowbit(int x) { return x & (-x); }

void solve() {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int mn = 31;
    while (q--) {
        int x; cin >> x;
        if (x >= mn) continue;
        mn = x;
        for (auto &y : arr) {
            int lb = lowbit(y);
            if (lb >= (1 << x)) y += (1 << (x - 1));
        }
    }
    for (auto x : arr) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

