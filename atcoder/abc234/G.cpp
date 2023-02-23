#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

/*
void tle() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<LL> dp(n, 0);
    LL pre_max = arr[0], pre_min = arr[0];
    for (int i = 1; i < n; i++) {
        pre_max = max(pre_max, arr[i]);
        pre_min = min(pre_min, arr[i]);
        dp[i] = pre_max - pre_min;

        LL suf_max = arr[i], suf_min = arr[i];
        for (int j = i - 1; j >= 0; j--) {
            dp[i] += dp[j] * (suf_max - suf_min) % MOD;
            suf_max = max(suf_max, arr[j]);
            suf_min = min(suf_min, arr[j]);
        }
    }

    for (auto x : dp) cerr << x % MOD << " ";
    cerr << endl;
}
*/

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    vector<LL> dp(n, 0);
    vector<pair<LL,LL>> suf_max, suf_min;
    LL pre_max = arr[0], pre_min = arr[0];
    for (int i = 1; i < n; i++) {
        // choose all (do not divide)
        LL old = (pre_max - pre_min) % MOD;
        pre_max = max(pre_max, arr[i]);
        pre_min = min(pre_min, arr[i]);
        dp[i] = (pre_max - pre_min) % MOD;
        // cerr << ".. i = " << i << ", dp[i] = " << dp[i] << endl;

        // deal with suffix
        if (i >= 3) {
            dp[i] = (dp[i] + dp[i - 1] - old + MOD) % MOD;
        }
        // cerr << ".. i = " << i << ", dp[i] = " << dp[i] << endl;

        LL acc = dp[i - 1];
        while (!suf_max.empty()) {
            auto [dp_suf_sum, max_val] = suf_max.back();
            if (arr[i] <= max_val) break;

            suf_max.pop_back();
            dp[i] = (dp[i] + dp_suf_sum * (arr[i] - max_val)) % MOD;
            // cerr << "[max] i = " << i << ", suf = " << dp_suf_sum << ", delta = " << arr[i] - max_val << endl;
            acc = (acc + dp_suf_sum) % MOD;
        }
        suf_max.emplace_back(acc, arr[i]);

        acc = dp[i - 1];
        while (!suf_min.empty()) {
            auto [dp_suf_sum, min_val] = suf_min.back();
            if (arr[i] >= min_val) break;

            suf_min.pop_back();
            dp[i] = (dp[i] + dp_suf_sum * (min_val - arr[i])) % MOD;
            // cerr << "[min] i = " << i << ", suf = " << dp_suf_sum << ", delta = " << min_val - arr[i] << endl;
            acc = (acc + dp_suf_sum) % MOD;
        }
        suf_min.emplace_back(acc, arr[i]);
    }

    cout << dp[n - 1] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}
