#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL INF = 1e15;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m, q; cin >> n >> m >> q;
    vector<vector<LL>> dist(n, vector<LL>(n, INF));
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        LL u, v, w; cin >> u >> v >> w; u--, v--;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for (int k = 0; k < n; k++) 
        for (int u = 0; u < n; u++) 
            for (int v = 0; v < n; v++) {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        if (dist[u][v] == INF) cout << -1 << "\n";
        else cout << dist[u][v] << "\n";
    }
}

