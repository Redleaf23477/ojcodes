#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using TLL = tuple<LL,LL>;

const LL INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<LL> arr(n+1, 0);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    vector<vector<LL>> dp_min(n+1, vector<LL>(n+1, INF));
    dp_min[0][0] = 0;
    for (int k = 1; k <= n; k++) {
        vector<TLL> stk;
        vector<LL> stk_min;
        for (int i = 1; i <= n; i++) {
            LL to_push_dp = dp_min[k-1][i-1];
            while (!stk.empty() && get<1>(stk.back()) <= arr[i]) {
                auto [pop_backped_dp, pop_backped_elem] = stk.back();
                stk.pop_back(), stk_min.pop_back();
                to_push_dp = min(to_push_dp, pop_backped_dp);
            }
            stk.emplace_back(to_push_dp, arr[i]);
            stk_min.emplace_back(min((stk_min.empty()? INF : stk_min.back()), to_push_dp + arr[i]));

            dp_min[k][i] = stk_min.back();
        }
    }

    /*
    vector<vector<LL>> dp_max(n+1, vector<LL>(n+1, 0));
    for (int k = 1; k <= n; k++) {
        vector<TLL> stk;
        vector<LL> stk_max;
        for (int i = 1; i <= n; i++) {
            LL to_push_dp = dp_max[k-1][i-1];
            while (!stk.empty() && get<1>(stk.back()) <= arr[i]) {
                auto [pop_backped_dp, pop_backped_elem] = stk.back();
                stk.pop_back(), stk_max.pop_back();
                to_push_dp = max(to_push_dp, pop_backped_dp);
            }
            stk.emplace_back(to_push_dp, arr[i]);
            stk_max.emplace_back(max((stk_max.empty()? 0 : stk_max.back()), to_push_dp + arr[i]));

            dp_max[k][i] = stk_max.back();
        }
    }
    */

    sort(arr.begin() + 1, arr.end(), greater<LL>());

    LL ans2 = 0;
    for (int k = 1; k <= n; k++) {
        ans2 += arr[k];
        cout << dp_min[k][n] << " " << ans2 << "\n";
    }
}
