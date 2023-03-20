#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, s, r; cin >> n >> s >> r;
    int max_dice = s - r;
    vector<int> ans(n, 1);
    ans[0] = max_dice;
    r -= (n-1);
    for (int i = 1; r > 0 && i < n; i++) {
        int use = min(r, max_dice-1);
        ans[i] += use;
        r -= use;
    }
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



