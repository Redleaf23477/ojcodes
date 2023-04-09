#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void run_dp(int n, vector<LL> arr, vector<LL> &dp, bool rev = false) {
    if (rev) {
        reverse(arr.begin(), arr.end());
    }

    // dp[i]: I explode on arr[i]
    //        how many additional cost do I need to clear arr[0:i-1]
    dp[0] = 0;
    LL acc = 0;
    vector<pair<int,int>> seg({{0,0}});
    for (int i = 1; i < n; i++) {
        int me_l = i, me_r = i;
        while (!seg.empty()) {
            auto [l, r] = seg.back();
            if (arr[r] >= arr[i] - (i - r)) {
                LL delta = arr[r] - (arr[i] - (i - r));
                acc += delta * (r - l + 1);
                me_l = l;
                seg.pop_back();
            } else {
                break;
            }
        }
        if (seg.empty()) {
            // delete the seg that goes under zero
            // also substract the underflow parts
            LL zero = i - arr[me_r];
            if (me_l < zero) {
                acc -= (zero - me_l) * (zero - me_l + 1) / 2;
                me_l = zero;
            }
        }
        seg.emplace_back(me_l, me_r);
        dp[i] = acc;
        /*
        cerr << "i = " << i << ", seg = {";
        for (auto [l, r] : seg) cerr << "(" << l << "," << r << "), ";
        cerr << "}" << endl;
        */
    }

    /*
    dp[0] = 0;
    LL acc = 0;  // the cost to push the necessary prefix to zero
    int j = 0;   // the next elem to push to zero
    LL window = arr[0];
    for (int i = 1; i < n; i++) {
        while (j < i && arr[i] - (i - j) <= 0) {
            // update acc and j
            acc += arr[j];
            window -= arr[j];
            j++;
        }

        LL triangle = 0;
        if (i != j) {
            triangle = ((arr[i] - 1) + (arr[i] - (i - j))) * (i - j) / 2;
        }
        dp[i] = acc + window - triangle;

        window += arr[i];

        cerr << "[dp]";
        if (rev) cerr << "[rev]";
        cerr << "(" << i << ", " << j << ")";
        cerr << "acc = " << acc << ", window = " << window << ", triangle = " << triangle << endl;
    }
    */

    if (rev) {
        reverse(dp.begin(), dp.end());
    }
}

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<LL> dp(n, 0), dp_rev(n, 0);
    run_dp(n, arr, dp, false);
    run_dp(n, arr, dp_rev, true);

    /*
    for (int i = 0; i < n; i++) {
        cerr << "i = " << i << ", dp = " << dp[i] << ", dp_rev = " << dp_rev[i] << ", elem = " << arr[i] << endl;
    }
    */

    LL ans = dp[0] + dp_rev[0] + arr[0];
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[i] + dp_rev[i] + arr[i]);
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



