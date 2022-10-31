#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        int ans = 0;
        for (auto &x : arr) ans = max(ans, x | k);
        cout << ans << "\n";
    }
}

