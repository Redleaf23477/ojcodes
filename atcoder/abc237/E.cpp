#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL INF = 1e14;
using T = tuple<LL,int>;  // (len, idx)

int n, m;
vector<LL> h, dist;
vector<vector<LL>> graph, dir_graph;


void build_dir_graph() {
    cin >> n >> m;
    h.assign(n, 0);
    graph.assign(n, vector<LL>());
    dir_graph.assign(n, vector<LL>());
    for (auto &x : h) cin >> x;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    priority_queue<T> roots;
    roots.emplace(h[0], 0);
    vector<bool> vis(n, false);
    while (!roots.empty()) {
        auto [_, u] = roots.top(); roots.pop();
        if (vis[u]) continue;
        priority_queue<T> pq;
        pq.emplace(h[u], u);
        while (!pq.empty()) {
            auto [_, u] = pq.top(); pq.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (auto v : graph[u]) {
                if (vis[v]) continue;
                dir_graph[u].emplace_back(v);
                if (h[v] > h[u]) {
                    roots.emplace(h[v], v);
                } else {
                    pq.emplace(h[v], v);
                }
            }
        }
    }
}

void solve() {
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; u++) {
        for (auto v : dir_graph[u]) {
            indeg[v] += 1;
        }
    }
    queue<int> q;
    vector<LL> dist(n, -INF);
    q.emplace(0), dist[0] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : dir_graph[u]) {
            LL len = dist[u] + (h[v] > h[u]? 2 * (h[u] - h[v]) : h[u] - h[v]);
            dist[v] = max(dist[v], len);
            if (--indeg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    cout << *max_element(dist.begin(), dist.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    build_dir_graph();
    /*
    for (int i = 0; i < n; i++) {
        cerr << i << " -> ";
        for (auto x : dir_graph[i]) cerr << x << " ";
        cerr << endl;
    }
    */
    solve();
}

