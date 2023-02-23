#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> ans(n, 0);

    int x = 1;
    for (int i = k-1; i < n; i += k) {
        ans[i] = x, x++;
    }
    int y = n;
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            ans[i] = y, y--;
        }
    }

    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

