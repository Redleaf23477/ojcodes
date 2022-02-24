#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<LL, int>;
constexpr LL INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<vector<Edge>> graph(2*n);
    for (int i = 0; i < m; i++) {
        LL u, v, w; cin >> u >> v >> w; u--, v--;
        graph[u].emplace_back(w, v);
        graph[u].emplace_back(w/2, v+n);
        graph[u+n].emplace_back(w, v+n);
    }
    vector<LL> dist(2*n, INF);
    dist[0] = 0;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [len, u] = pq.top(); pq.pop();
        if (len > dist[u]) continue;
        for (auto [w, v] : graph[u]) {
            LL new_len = dist[u] + w;
            if (new_len < dist[v]) {
                dist[v] = new_len;
                pq.emplace(dist[v], v);
            }
        }
    }
    cout << min(dist[n-1], dist[2*n-1]) << "\n";
}

