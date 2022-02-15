#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9 + 7;

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
    vector<LL> ans(n, 0);
    ans[0] = 1;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) q.emplace(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : graph[u]) {
            ans[v] = (ans[v] + ans[u]) % MOD;
            if (--indeg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    cout << ans[n-1] << "\n";
    
}