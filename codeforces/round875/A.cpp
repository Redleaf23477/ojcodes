#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = pair<int,int>;

void solve() {
    int n; cin >> n;
    vector<vector<Edge>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(i, v);
        tree[v].emplace_back(i, u);
    }
    for (int i = 0; i < n; i++) {
        sort(tree[i].begin(), tree[i].end());
    }
    function<int(int,int,int)> dfs = [&](int u, int pa, int pa_idx) {
        int ans = 1;
        for (auto [idx, v] : tree[u]) {
            if (v == pa) continue;
            int reset = 0;
            if (idx < pa_idx) reset = 1;
            ans = max(ans, reset + dfs(v, u, idx));
        }
        return ans;
    };
    cout << dfs(0, 0, 0) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



