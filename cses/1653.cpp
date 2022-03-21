#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<int,int>;

void update(T &dp, T cand) {
    auto [dp_cnt, dp_rem] = dp;
    auto [cand_cnt, cand_rem] = cand;

    if (cand_cnt < dp_cnt) dp = cand;
    else if (cand_cnt == dp_cnt && cand_rem > dp_rem) dp = cand;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, x; cin >> n >> x;
    vector<int> arr(n);
    for (auto &a : arr) cin >> a;

    vector<T> dp((1<<n), T(2*n, 0));
    dp[0] = T(0, 0);
    for (int m = 0; m < (1<<n); m++) {
        for (int b = 0; b < n; b++) if ((m >> b) & 1) {
            auto [cnt, rem] = dp[m ^ (1<<b)];
            if (rem >= arr[b]) {
                update(dp[m], T(cnt, rem - arr[b]));
            } else {
                update(dp[m], T(cnt+1, x - arr[b]));
            }
        }
    }
    cout << get<0>(dp[(1<<n)-1]) << "\n";
}

