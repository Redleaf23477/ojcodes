#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<LL> gcds;

    for (int l = 0, r = n-1; l < r; l++, r--) {
        if (arr[l] != arr[r]) {
            gcds.emplace_back(abs(arr[l] - arr[r]));
        }
    }

    if (gcds.empty()) {
        cout << 0 << "\n";
    } else {
        LL g = gcds[0];
        for (size_t i = 1; i < gcds.size(); i++) {
            g = gcd(g, gcds[i]);
        }
        cout << g << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



