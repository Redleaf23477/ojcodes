#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    vector<LL> cnt(n + m, 0);
    vector<vector<int>> in_tim(n + m);
    vector<int> arr(n);
    for (auto &x : arr) {
        cin >> x; x--;
        in_tim[x].emplace_back(0);
    }
    for (int t = 1; t <= m; t++) {
        int pos, val; cin >> pos >> val; pos--, val--;
        // out
        int bye = arr[pos];
        if (in_tim[bye].size() == 1) {
            cnt[bye] += t - in_tim[bye].back();
        }
        in_tim[bye].pop_back();
        // in
        in_tim[val].emplace_back(t);
        arr[pos] = val;
    }
    for (auto &bye : arr) {
        if (in_tim[bye].size() == 1) {
            cnt[bye] += m + 1 - in_tim[bye].back();
        }
        in_tim[bye].pop_back();
    }

    /*
    cerr << "debug: " << endl;
    for (int num = 0; num < n + m; num++) {
        cerr << num + 1 << " => " << cnt[num] << endl;
    }
    */

    LL ans = 0;
    for (auto Y : cnt) {
        LL N = 1 + m - Y;
        ans += Y * (Y - 1) / 2 + Y * N;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

