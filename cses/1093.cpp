#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL fastpw(LL a, LL p, LL MOD) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    int sum = n * (n+1) / 2;
    constexpr int MOD = 1e9 + 7;
    int inv2 = fastpw(2, MOD-2, MOD);
    vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= sum; s++) {
            dp[i][s] = dp[i-1][s];
            if (s >= i) dp[i][s] += dp[i-1][s-i];
            dp[i][s] %= MOD;
        }
    }
    /*
    for (int i = 0; i <= n; i++) for (int j = 0; j <= sum; j++) {
        cerr << dp[i][j] << " \n"[j==sum];
    }
    */
    if (sum % 2 == 0) {
        cout << (LL)dp[n][sum / 2] * inv2 % MOD << "\n";
    } else {
        cout << 0 << "\n";
    }
}

