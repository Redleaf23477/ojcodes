#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

inline void add_self(LL &lhs, LL rhs) {
    lhs = (lhs + rhs) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<LL>> dp(2, vector<LL>(1<<n, 0));
    dp[0][(1<<n)-1] = 1;
    for (int x = 0; x < n*m; x++) {
        cerr << "x = " << x << endl;
        int i = x % 2, j = 1 - i;
        int r = x / n, c = x % n;  // new cell to be done
        fill(dp[j].begin(), dp[j].end(), 0);
        for (int s = 0; s < (1<<n); s++) {
            int newest = s >> (n-1);
            int oldest = s & 1;
            if (newest == 1 && oldest == 1) {
                add_self(dp[j][(s >> 1)], dp[i][s]);
            } else if (newest == 1 && oldest == 0) {
                add_self(dp[j][(s >> 1) + (1 << (n-1))], dp[i][s]);
            } else if (newest == 0 && oldest == 1) {
                if (c != 0) add_self(dp[j][(s >> 1) + (3 << (n-2))], dp[i][s]);  // put left
                add_self(dp[j][(s >> 1)], dp[i][s]);
            } else if (newest == 0 && oldest == 0) {
                add_self(dp[j][(s >> 1) + (1 << (n-1))], dp[i][s]);
            } else {
                assert(false && "unreachable");
            }
        }
    }
    cout << dp[n * m % 2][(1<<n)-1] << "\n";
}