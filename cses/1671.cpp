#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<LL,int>;  // (len, idx)

constexpr LL INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        graph[u].emplace_back(w, v);
    }
    // sssp
    vector<LL> dist(n, INF); dist[0] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [len, u] = pq.top(); pq.pop();
        if (len > dist[u]) continue;
        for (auto [w, v] : graph[u]) {
            LL new_len = len + w;
            if (new_len < dist[v]) {
                dist[v] = new_len;
                pq.emplace(dist[v], v);
            }
        }
    }
    for (auto x : dist) cout << x << " ";
    cout << "\n";
}

