#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    LL k; cin >> k;
    vector<LL> A(n);
    for (auto &x : A) {
        cin >> x;
    }
    vector<LL> dep(n, -1);
    vector<LL> pref_sum;
    LL ans = 0;
    bool in_cycle = false;
    for (LL i = 0, x = 0; i < k; i++) {
        ans += A[x];
        pref_sum.emplace_back(ans);
        if (dep[x] == -1 || in_cycle) {
            dep[x] = i;
            x = (x + A[x]) % n;
        } else {
            in_cycle = true;
            LL cyc_len = i - dep[x];
            LL remaining = k - i - 1;
            LL cyc_cnt = remaining / cyc_len;
            i += cyc_cnt * cyc_len;

            LL cyc_sum = pref_sum.back() - pref_sum[dep[x]];
            ans += cyc_sum * cyc_cnt;
            x = (x + A[x]) % n;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



