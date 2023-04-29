#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<int> find_dep(int root, vector<vector<int>> const &tree) {
    int n = tree.size();
    vector<int> ans(n, 0);
    function<void(int,int)> dfs = [&](int u, int pa) {
        for (auto v : tree[u]) {
            if (v == pa) continue;
            ans[v] = ans[u] + 1;
            dfs(v, u);
        }
    };
    dfs(root, root);
    return ans;
}

void solve() {
    int n; cin >> n;
    LL k, c; cin >> k >> c;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    auto rooted_0 = find_dep(0, tree);
    int x = max_element(rooted_0.begin(), rooted_0.end()) - rooted_0.begin();
    auto rooted_x = find_dep(x, tree);
    int y = max_element(rooted_x.begin(), rooted_x.end()) - rooted_x.begin();
    auto rooted_y = find_dep(y, tree);

    LL ans = 0;
    for (int r = 0; r < n; r++) {
        LL strategy = 0;
        // move root 
        strategy -= c * rooted_0[r];
        // tree cost
        strategy += k * max(rooted_x[r], rooted_y[r]);

        ans = max(ans, strategy);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



