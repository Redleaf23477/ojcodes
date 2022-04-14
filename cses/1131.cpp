#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> graph(n);
    vector<int> indeg(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        indeg[u]++, indeg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 1) q.emplace(i);
    }
    int ans = 1;
    vector<int> dist(n, 1);
    vector<bool> popped(n, false);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        popped[u] = true;
        for (auto v : graph[u]) {
            if (!popped[v]) {
                ans = max(ans, dist[u] + dist[v]);
                dist[v] = max(dist[v], dist[u] + 1);
                if (--indeg[v] == 1) q.emplace(v);
            }
        }
    }
    cout << ans-1 << "\n";
}