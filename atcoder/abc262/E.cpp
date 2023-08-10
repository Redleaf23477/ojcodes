#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        p /= 2;
        x = x * x % MOD;
    }
    return ans;
}

void solve() {
    int N, M, K; cin >> N >> M >> K;

    vector<LL> fac(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }
    vector<LL> fac_inv(N + 1);
    fac_inv[N] = fastpw(fac[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
        fac_inv[i] = fac_inv[i + 1] * (i + 1) % MOD;
    }
    auto C = [&](int n, int m) {
        return fac[n] * fac_inv[m] % MOD * fac_inv[n - m] % MOD;
    };

    vector<int> deg(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        deg[u]++, deg[v]++;
    }
    int odd = 0, even = 0;
    for (int i = 0; i < N; i++) {
        odd += (deg[i] % 2 == 1);
        even += (deg[i] % 2 == 0);
    }
    LL ans = 0;
    for (int o = 0; o <= K; o += 2) {
        int e = K - o;
        if (odd >= o && even >= e) {
            ans += C(odd, o) * C(even, e);
            ans %= MOD;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



