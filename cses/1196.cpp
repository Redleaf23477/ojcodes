#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<LL, int>;  // (len, idx)
constexpr LL INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m, k; cin >> n >> m >> k;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        graph[u].emplace_back(w, v);
    }

    vector<vector<LL>> dist(n, vector<LL>(k+1, INF));
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    dist[0].front() = 0, pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [len, u] = pq.top(); pq.pop();
        if (len > dist[u][k-1]) continue;

        for (auto [w, v] : graph[u]) {
            LL new_len = len + w;
            dist[v][k] = new_len;
            for (int i = k; i > 0; i--) {
                if (dist[v][i] < dist[v][i-1]) {
                    swap(dist[v][i], dist[v][i-1]);
                } else {
                    break;
                }
            }
            if (dist[v][k] > new_len) {
                pq.emplace(new_len, v);
            }
        }
    }

    for (int i = 0; i < k; i++) {
        cout << dist[n-1][i] << " ";
    }
    cout << "\n";
}

