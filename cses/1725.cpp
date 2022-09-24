#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, a, b; cin >> n >> a >> b;
    vector<vector<double>> dp(n+1, vector<double>(6 * n + 1, 0));
    dp[0][0] = 1;
    for (int round = 1; round <= n; round++) {
        for (int val = 0; val <= 6 * n; val++) {
            for (int dice = 1; dice <= 6; dice++) {
                if (val - dice >= 0) {
                    dp[round][val] += 1.0 / 6.0 * dp[round - 1][val - dice];
                }
            }
        }
    }
    cout << fixed << setprecision(6) << accumulate(dp.back().begin() + a, dp.back().begin() + b + 1, 0.0) << "\n";
}

