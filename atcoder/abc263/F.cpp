#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    int M = (1 << N);
    vector<vector<LL>> C(N, vector<LL>(M));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> C[j][i];
        }
    }

    // dp[height][root]
    vector<vector<LL>> dp(N, vector<LL>(M, 0));
    for (int i = 0; i < M; i++) {
        dp[0][i] = C[0][i];
    }
    for (int h = 1; h < N; h++) {
        int sz = (1 << (h + 1));
        for (int t = 0; t < M; t += sz) {
            int L = t, mid = L + sz / 2, R = L + sz;
            LL lmax = 0, rmax = 0;
            for (int i = L; i < mid; i++) lmax = max(lmax, dp[h-1][i]);
            for (int i = mid; i < R; i++) rmax = max(rmax, dp[h-1][i]);

            for (int i = L; i < mid; i++) {
                dp[h][i] = dp[h-1][i] + C[h][i] - C[h-1][i] + rmax;
            }
            for (int i = mid; i < R; i++) {
                dp[h][i] = dp[h-1][i] + C[h][i] - C[h-1][i] + lmax;
            }
        }
    }
    cout << *max_element(dp[N-1].begin(), dp[N-1].end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



