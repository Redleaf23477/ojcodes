#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct BIT {
    int n; 
    vector<LL> bit;
    BIT(int _n) : n(_n), bit(n + 1, 0) {}
    int lowbit(int x) { return x & (-x); }
    void modify(int x, int val) {
        for (; x <= n; x += lowbit(x)) {
            bit[x] += val;
        }
    }
    LL query(int x) {
        LL ans = 0;
        for (; x > 0; x -= lowbit(x)) {
            ans += bit[x];
        }
        return ans;
    }
};

// use 1 index
void solve() {
    int q; cin >> q;
    vector<int> node_ver(2, 0);
    vector<vector<int>> tree(2);
    vector<vector<pair<int,int>>> add(2);  // add[node] = {(time, val)}
    for (int i = 1; i <= q; i++) {
        int op; cin >> op;
        if (op == 1) {
            int u; cin >> u;
            int v = tree.size();
            tree.resize(tree.size() + 1);
            add.resize(add.size() + 1);
            node_ver.emplace_back(i);

            tree[u].emplace_back(v);
            tree[v].emplace_back(u);
        } else {
            int v, x; cin >> v >> x;
            add[v].emplace_back(i, x);
        }
    }
    BIT bit(q + 1);
    vector<LL> ans(tree.size(), 0);
    function<void(int,int)> dfs = [&](int u, int pa) {
        // push value
        for (auto [ver, val] : add[u]) {
            bit.modify(ver, val);
        }
        // my value
        ans[u] = bit.query(q) - bit.query(node_ver[u] - 1);
        // dfs
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dfs(v, u);
        }
        // pop value
        for (auto [ver, val] : add[u]) {
            bit.modify(ver, -val);
        }
    };
    dfs(1, 1);

    for (int i = 1; i < (int)ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

