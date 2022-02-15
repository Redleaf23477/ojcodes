#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<LL, int>;
constexpr LL MOD = 1e9 + 7;
constexpr LL INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        graph[u].emplace_back(w, v);
    }
    // dijk
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<LL> dist(n, INF);
    dist[0] = 0, pq.emplace(0, 0);
    while (!pq.empty()) {
        auto [len, u] = pq.top(); pq.pop();
        if (len > dist[u]) continue;
        for (auto [w, v] : graph[u]) {
            LL new_len = len + w;
            if (dist[v] > new_len) {
                dist[v] = new_len;
                pq.emplace(dist[v], v);
            }
        }
    }
    // build sssp dag
    vector<vector<int>> dag(n);
    vector<int> dag_indeg(n, 0);
    for (int u = 0; u < n; u++) {
        for (auto [w, v] : graph[u]) {
            if (dist[v] == dist[u] + w) {
                dag[u].emplace_back(v);
                dag_indeg[v] += 1;
            }
        }
    }
    // dp: all the answers
    queue<int> q;
    vector<LL> path_cnt(n, 0), min_len(n, INF), max_len(n, 0);
    path_cnt[0] = 1, min_len[0] = max_len[0] = 0, q.emplace(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : dag[u]) {
            path_cnt[v] = (path_cnt[v] + path_cnt[u]) % MOD;
            min_len[v] = min(min_len[v], min_len[u] + 1);
            max_len[v] = max(max_len[v], max_len[u] + 1);
            if (--dag_indeg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    cout << dist[n-1] << " " << path_cnt[n-1] << " " << min_len[n-1] << " " << max_len[n-1] << "\n";
}