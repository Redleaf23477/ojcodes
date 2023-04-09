#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> sweep(51, 0);
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        if (l <= k && k <= r) {
            sweep[l]++, sweep[r+1]--;
        }
    }
    partial_sum(sweep.begin(), sweep.end(), sweep.begin());
    bool ans = true;
    for (int i = 0; i <= 50; i++) {
        if (i != k && sweep[i] >= sweep[k]) {
            ans = false;
        }
    }
    cout << (ans? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



