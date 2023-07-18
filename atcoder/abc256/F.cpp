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

struct BIT {
    int n;
    vector<LL> bit;
    int lowbit(int x) { return x & (-x); }
    BIT(int _n) : n(_n), bit(n + 1, 0) {}
    void add(int pos, LL val) {
        for (; pos <= n; pos += lowbit(pos)) {
            bit[pos] = (bit[pos] + val) % MOD;
        }
    }
    LL sum(LL pos) {
        LL ans = 0;
        for (; pos > 0; pos -= lowbit(pos)) {
            ans = (ans + bit[pos]) % MOD;
        }
        return ans;
    }
};

void solve() {
    int N, Q; cin >> N >> Q;
    vector<LL> A(N);
    for (auto &x : A) cin >> x;
    BIT zero(N), one(N), two(N);
    for (LL i = 1; i <= N; i++) {
        zero.add(i, A[i - 1]);
        one.add(i, i * A[i - 1] % MOD);
        two.add(i, i * i % MOD * A[i - 1] % MOD);
    }

    LL inv2 = fastpw(2, MOD - 2);

    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            LL x; cin >> x;
            LL val; cin >> val; val %= MOD;
            val = (val - A[x - 1] + MOD) % MOD;
            A[x - 1] = (A[x - 1] + val) % MOD;
            zero.add(x, val);
            one.add(x, x * val % MOD);
            two.add(x, x * x % MOD * val % MOD);
        } else {
            LL x; cin >> x;
            LL ans = (x + 2) % MOD * (x + 1) % MOD * inv2 % MOD * zero.sum(x) % MOD;
            ans = (ans + (-3 - 2 * x + MOD) % MOD * inv2 % MOD * one.sum(x) % MOD) % MOD;
            ans = (ans + inv2 * two.sum(x) % MOD) % MOD;
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



