#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL fastpw(LL x, LL pw, LL mod) {
    LL ans = 1;
    while (pw > 0) {
        if (pw % 2 == 1) ans = ans * x % mod;
        x = x * x % mod;
        pw /= 2;
    }
    return ans;
}

LL modinv(LL x, LL p) {
    return fastpw(x, p - 2, p); 
}

LL ceil_div(LL n, LL d) {
    return (n + d - 1) / d;
}

void even(LL n, LL p) {
    vector<vector<LL>> dp(n/2+1, vector<LL>(n/2+1, 0));
    // dp[diag][dummy]
    dp[0][1] = 1;
    for (LL diag = 1; diag <= n/2; diag++) {
        for (LL dummy = diag; dummy <= n/2; dummy++) {
            dp[diag][dummy] = 2 * diag * dp[diag-1][dummy] % p;
            if (dummy - 1 >= diag) {
                dp[diag][dummy] = (dp[diag][dummy] + dummy * dp[diag][dummy-1]) % p;
            }
        }
    }
    cout << dp[n/2][n/2] << "\n";
}

void odd(LL n, LL p) {
    LL m = ceil_div(ceil_div(n - 1, 2), 2);
    LL k = n - 1 - m - m;
    // cerr << "n = " << n << ", m = " << m << ", k = " << k << endl;
    vector<vector<vector<LL>>> dp(m + 1, vector<vector<LL>>(m + 1, vector<LL>(k + 1, 0)));
    // dp[L][R][dummy]
    for (LL d = 0; d <= k; d++) {
        dp[1][0][d] = dp[0][1][d] = 1;
    }
    for (LL l = 1; l <= m; l++) {
        for (LL r = 1; r <= m; r++) {
            // d = 0
            dp[l][r][0] = (dp[l][r][0] + l * dp[l-1][r][0]) % p;
            dp[l][r][0] = (dp[l][r][0] + r * dp[l][r-1][0]) % p;
            for (LL d = 1; d <= k; d++) {
                dp[l][r][d] = d * dp[l][r][d-1] % p;
                dp[l][r][d] = (dp[l][r][d] + l * dp[l-1][r][d]) % p;
                dp[l][r][d] = (dp[l][r][d] + r * dp[l][r-1][d]) % p;
            }
        }
    }
    /*
    cerr << "dp = " << endl;
    for (LL l = 0; l <= m; l++) {
        for (LL r = 0; r <= m; r++) {
            cerr << dp[l][r][0] << " ";
        }
        cerr << endl;
    }
    */
    cout << n * m * m % p * modinv(2, p) % p * dp[m][m][k] % p << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL n, p; cin >> n >> p;
    if (n % 2 == 0) even(n, p);
    else odd(n, p);
}

