#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<int,int>;  // (v, edge_idx)
 
int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<int> indeg(n, 0);
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v, i);
        indeg[u] += 1, indeg[v] += 1;
    }
 
    auto valid = [&]() {
        bool odd_1 = indeg[0] % 2;
        bool odd_n = indeg[n-1] % 2;
        for (int i = 1; i < n-1; i++) {
            if (indeg[i] % 2 != 0) return false;
        }
        return odd_1 && odd_n;
    };
 
    vector<bool> used(m, false);
    vector<int> ans;
    vector<vector<Edge>::iterator> eit(n);
    function<void(int)> dfs = [&](int u) {
        while (eit[u] != graph[u].end()) {
            auto [v, eid] = *eit[u]; eit[u]++;
            if (!used[eid]) {
                used[eid] = true;
                dfs(v);
            }
        }
        ans.emplace_back(u + 1);
    };
 
    if (!valid()) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < n; i++) {
            eit[i] = graph[i].begin();
        }
        dfs(0);
        if (find(used.begin(), used.end(), false) != used.end()) {
            cout << "IMPOSSIBLE\n";
        } else {
            reverse(ans.begin(), ans.end());
            for (auto x : ans) {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}
