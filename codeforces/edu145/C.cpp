#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> ans(n, -1000);
    for (int i = 0, combo = 1; i < n; i++) {
        if ((combo + 1) * (combo) / 2 <= k) {
            ans[i] = 1;
            combo++;
        } else {
            combo--;
            k -= (combo + 1) * (combo) / 2;
            combo = 1;
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



