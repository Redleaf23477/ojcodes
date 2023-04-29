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

LL modinv(LL x) { return fastpw(x, MOD-2); }

void solve() {
    int n, s, t; cin >> n >> s >> t; s--, t--;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    vector<int> st_path;
    vector<bool> in_st_path(n, false);
    vector<LL> ans(n, 0);
    function<bool(int,int)> do_s_t_path = [&](int u, int pa) {
        st_path.emplace_back(u);
        if (u == t) {
            for (int i = st_path.size() - 2; i >= 0; i--) {
                int x = st_path[i], y = st_path[i+1];
                ans[x] = (1 + tree[x].size() - 1 + ans[y] * modinv(tree[y].size()) % MOD) % MOD;
            }
            ans[t] = 1;
            return true;
        } else {
            for (auto v : tree[u]) {
                if (v == pa) continue;
                bool res = do_s_t_path(v, u);
                if (res) return true;
            }
            st_path.pop_back();
            return false;
        }
    };
    function<void(int,int)> solve_sub = [&](int u, int pa) {
        for (auto v : tree[u]) {
            if (v == pa) continue;
            if (in_st_path[v]) continue;
            ans[v] = (tree[v].size() - 1 + ans[u] * modinv(tree[u].size()) % MOD) % MOD;
            solve_sub(v, u);
        }
    };
    do_s_t_path(s, s);
    for (auto x : st_path) in_st_path[x] = true;
    for (auto x : st_path) {
        solve_sub(x, x);
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



