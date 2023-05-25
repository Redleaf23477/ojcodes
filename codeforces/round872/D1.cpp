#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9 + 7;

LL fastpw(LL a, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * a % MOD;
        p /= 2;
        a = a * a % MOD;
    }
    return ans;
}

LL modinv(LL x) { return fastpw(x, MOD-2); }

LL C_n_2(LL n) {
    return n * (n-1) % MOD * modinv(2) % MOD;
}

LL k2_case(int n, vector<vector<int>> const &tree) {
    LL ans = 0;
    vector<LL> sz(n, 0);
    function<void(int,int,LL)> dfs1 = [&](int u, int pa, LL dep) {
        sz[u] = 1;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dfs1(v, u, dep + 1);
            sz[u] += sz[v];
        }
    };
    dfs1(0, 0, 1);
    function<void(int,int)> dfs2 = [&](int u, int pa) {
        ans = (ans + n - 1) % MOD;
        LL acc = 0;
        for (auto v : tree[u]) {
            acc = (acc + sz[v] * (n - 1 - sz[v])) % MOD;
        }
        ans = (ans + acc * modinv(2)) % MOD;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            LL bk_u = sz[u];
            LL bk_v = sz[v];

            sz[u] = n - sz[v];
            sz[v] = n;
            dfs2(v, u);

            sz[u] = bk_u;
            sz[v] = bk_v;
        }
    };
    dfs2(0, 0);
    return ans;
}

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    if (k == 1) {
        cout << 1 << "\n";
    } else if (k == 2) {
        cout << k2_case(n, tree) * modinv(C_n_2(n)) % MOD << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



