#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL N = 2e6 + 1;
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

vector<LL> fac(N + 1, 1), fac_inv(N + 1, 1);

LL C(LL n, LL k) {
    return fac[n] * fac_inv[k] % MOD * fac_inv[n - k] % MOD;
}

LL cnt(LL n, LL k) {
    // a1 + a2 + ... + an = k
    return C(n - 1 + k, k);
}

void solve() {
    for (int i = 2; i <= N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    fac_inv[N] = fastpw(fac[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        fac_inv[i] = fac_inv[i + 1] * (i + 1) % MOD;
    }
    for (int i = N; i >= 0; i--) {
        assert(fac[i] * fac_inv[i] % MOD == 1);
    }

    LL R, G, B, K; cin >> R >> G >> B >> K;
    LL ans = 1;
    // step 1: put R and B
    ans = fac[R + B] * fac_inv[R] % MOD * fac_inv[B] % MOD;

    // step 2: insert G according to K
    ans = ans * C(R, K) % MOD * cnt(1 + K + B, G - K) % MOD;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}