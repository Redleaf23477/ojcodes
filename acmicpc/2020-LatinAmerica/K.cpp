#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

const LL MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL k, err; cin >> k >> err;
    vector<vector<LL>> K(k, vector<LL>(k, 0));
    for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) {
        cin >> K[i][j];
    }

    int n; cin >> n;
    vector<LL> pass(n);
    for (int i = 1; i < n; i++) cin >> pass[i];

    vector<vector<LL>> dp(2, vector<LL>(k + 1, 1));
    for (int i = 1; i < n; i++) {
        auto &dest= dp[i%2];
        auto &source = dp[1 - i%2];
        fill(dest.begin(), dest.end(), 0);

        for (int from = 0; from < k; from++) {
            auto it = upper_bound(K[from].begin(), K[from].end(), pass[i] + err);
            if (it == K[from].begin()) continue;
            int R = it - K[from].begin();

            it = lower_bound(K[from].begin(), K[from].end(), pass[i] - err);
            if (it == K[from].end()) continue;
            int L = it - K[from].begin();

            dest[L] = (dest[L] + source[from]) % MOD;
            dest[R] = (dest[R] - source[from] + MOD) % MOD;
        }

        for (int i = 1; i < k; i++) {
            dest[i] = (dest[i] + dest[i-1]) % MOD;
        }
    }

    LL ans = 0;
    for (int i = 0; i < k; i++) {
        ans = (ans + dp[(n-1) % 2][i]) % MOD;
    }
    cout << ans << "\n";
}

