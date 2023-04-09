#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    vector<pair<int,int>> tim(n);
    int t = 1;
    function<void(int,int)> dfs = [&](int u, int pa) {
        tim[u].first = t;
        bool first = true;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            if (!first) t++;
            if (first) first = false;
            dfs(v, u);
        }
        tim[u].second = t;
    };
    dfs(0, 0);
    for (auto [l, r] : tim) {
        cout << l << " " << r << "\n";
    }
}

