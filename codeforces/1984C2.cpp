#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL MOD = 998244353;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    LL mx = 0, mn = 0;
    map<LL,LL> cnt;
    cnt[0] = 1;
    for (auto x : arr) {
        LL new_mx = max(mx + x, abs(mn + x));
        LL new_mn = mn + x;

        map<LL,LL> new_cnt;
        new_cnt[new_mx] = new_cnt[new_mn] = 0;

        for (auto [v, c] : cnt) {
            for (auto v2 : {v + x, abs(v + x)}) {
                if (v2 == new_mx || v2 == new_mn) {
                    new_cnt[v2] = (new_cnt[v2] + c) % MOD;
                }
            }
        }

        mx = new_mx, mn = new_mn;
        cnt = new_cnt;
    }


    cout << cnt.rbegin()->second << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

