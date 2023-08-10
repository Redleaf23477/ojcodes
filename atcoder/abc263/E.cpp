#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p /= 2;
    }
    return ans;
}

LL inv(LL x) { return fastpw(x, MOD - 2); }

void solve() {
    int N; cin >> N;
    vector<int> A(N - 1);
    for (auto &x : A) cin >> x;

    vector<LL> dp(N + 1, 0);
    for (int i = N - 2; i >= 0; i--) {
        dp[i] = ((dp[i + 1] - dp[i + A[i] + 1] + MOD) % MOD * inv(A[i]) + (A[i] + 1) * inv(A[i]) % MOD) % MOD;
        dp[i] = (dp[i] + dp[i + 1]) % MOD;
    }
    cout << (dp[0] - dp[1] + MOD) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



