#pragma GCC target("popcnt")
#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

using bset = bitset<50000>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> indeg(n, 0);
    vector<vector<int>> graph(n);
    for (int e = 0; e < m; e++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[v].emplace_back(u);
        indeg[u]++;
    }

    vector<bset> decendents(n, bset(0));
    vector<int> ans(n, 0);
    auto merge = [&](bset &from, bset &to) {
        to |= from;
    };

    queue<int> Q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) {
        Q.emplace(i); 
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        decendents[u][u] = true;
        ans[u] = decendents[u].count();
        for (auto v : graph[u]) {
            merge(decendents[u], decendents[v]);
            if (--indeg[v] == 0) Q.emplace(v);
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}

