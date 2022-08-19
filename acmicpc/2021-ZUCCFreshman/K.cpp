#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> color(n);
    for (auto &x : color) cin >> x;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<int> group(n, -1), gsize;
    function<int(int,int)> dfs1 = [&](int u, int g) {
        group[u] = g;
        int ans = 1;
        for (auto v : graph[u]) {
            if (group[v] == -1 && color[u] == color[v]) {
                ans += dfs1(v, g);
            }
        }
        return ans;
    };
    for (int i = 0; i < n; i++) {
        if (group[i] == -1) {
            int gid = gsize.size();
            gsize.emplace_back(dfs1(i, gid));
        }
    }

    int ans = *max_element(gsize.begin(), gsize.end());
    for (int u = 0; u < n; u++) {
        map<int,set<int>> col_group;
        for (auto v : graph[u]) {
            col_group[color[v]].insert(group[v]);
        }
        for (auto &[col, s] : col_group) {
            if (col == color[u]) continue;
            int sz_sum = 0;
            for (auto g : s) sz_sum += gsize[g];
            ans = max(ans, sz_sum + 1);
        }
    }
    cout << ans << "\n";
}

