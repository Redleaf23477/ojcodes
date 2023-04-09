#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> tea(n);
    for (auto &x : tea) cin >> x;
    vector<LL> taster(n);
    for (auto &x : taster) cin >> x;
    vector<LL> taster_sum(n);
    partial_sum(taster.begin(), taster.end(), taster_sum.begin());

    for (int i = 1; i < n; i++) {
        tea[i] += taster_sum[i-1];
    }
    vector<LL> tea_sum(n);
    partial_sum(tea.begin(), tea.end(), tea_sum.begin());

    vector<LL> ans(n, 0);
    vector<LL> sweep(n+1, 0);
    for (auto t : tea) {
        auto it = upper_bound(taster_sum.begin(), taster_sum.end(), t);
        int idx = it - taster_sum.begin();
        sweep[0]++, sweep[idx]--;
        if (idx != n) {
            LL rest = t - (idx == 0? 0 : taster_sum[idx - 1]);
            ans[idx] += rest;
        }
    }
    partial_sum(sweep.begin(), sweep.end(), sweep.begin());

    for (int i = 0; i < n; i++) {
        cout << ans[i] + taster[i] * (sweep[i] - (n - i - 1)) << " ";
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



