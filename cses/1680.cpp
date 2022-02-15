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
    vector<LL> ans(n, 0), backtrack(n, -1);
    ans[0] = 1;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) q.emplace(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : graph[u]) {
            if (ans[u] != 0 && ans[v] < ans[u] + 1) {
                ans[v] = ans[u] + 1;
                backtrack[v] = u;
            }
            if (--indeg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    if (ans[n-1] == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << ans[n-1] << "\n";
        vector<int> path;
        for (int u = n-1; u != -1; u = backtrack[u]) {
            path.emplace_back(u);
        }
        for (auto it = path.rbegin(); it != path.rend(); it++) {
            cout << *it + 1 << " ";
        }
        cout << "\n";
    }
    
}