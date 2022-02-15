#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        indeg[v] += 1;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) q.emplace(i);
    }
    vector<int> ans;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.emplace_back(u);
        for (auto v : graph[u]) {
            if (--indeg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    if (ans.size() != n) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (auto x : ans) cout << x+1 << " ";
        cout << "\n";
    }
}