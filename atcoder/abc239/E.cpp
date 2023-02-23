#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr size_t K = 20;

vector<int> merge(vector<int> &lhs, vector<int> &rhs) {
    vector<int> ans;
    size_t i = 0, j = 0; 
    while (ans.size() < K && i < lhs.size() && j < rhs.size()) {
        if (lhs[i] > rhs[j]) ans.emplace_back(lhs[i]), i++;
        else ans.emplace_back(rhs[j]), j++;
    }
    while (ans.size() < K && i < lhs.size()) ans.emplace_back(lhs[i]), i++;
    while (ans.size() < K && j < rhs.size()) ans.emplace_back(rhs[j]), j++;
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, Q; cin >> n >> Q;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    vector<vector<int>> ans(n, vector<int>());
    function<void(int,int)> dfs = [&](int u, int pa) {
        ans[u].emplace_back(arr[u]);
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dfs(v, u);
            ans[u] = merge(ans[u], ans[v]);
        }
    };
    dfs(0, 0);

    while (Q--) {
        int u, k; cin >> u >> k; u--, k--;
        cout << ans[u][k] << "\n";
    }
}

