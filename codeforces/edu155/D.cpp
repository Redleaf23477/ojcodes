#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL MOD = 998244353;

LL run(int b, vector<LL> &arr, int n) {
    LL one_cnt = 0, weighted_sum = 0;
    for (int i = 0, x = 0; i < n; i++) {
        if ((arr[i] >> b) & 1) {
            x ^= 1;
        }
        one_cnt += (x == 1);
        weighted_sum += (x == 1) * (i + 1);
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans = (ans + weighted_sum) % MOD;
        if ((arr[i] >> b) & 1) {
            LL m = n - i;
            one_cnt = m - one_cnt;
            weighted_sum = (1 + m) * m / 2 - weighted_sum;
        }
        weighted_sum -= one_cnt;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    LL ans = 0;
    for (int b = 0; b < 30; b++) {
        LL tmp = run(b, arr, n) * (1 << b) % MOD;
        ans = (ans + tmp) % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}

