#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr int INF = 1e9;

vector<int> bfs(int s, vector<vector<int>> const &graph) {
    vector<int> dist(graph.size(), INF);
    queue<int> Q;
    dist[s] = 0, Q.emplace(s);
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto v : graph[u]) {
            if (dist[v] == INF) {
                dist[v] = dist[u] + 1;
                Q.emplace(v);
            }
        }
    }
    return dist;
}

void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<int> dist_1 = bfs(1, graph);
    vector<int> dist_n = bfs(N, graph);

    for (int i = 1; i <= N; i++) {
        LL ans = min({dist_1[N], dist_1[0] + dist_n[i], dist_1[i] + dist_n[0]});
        cout << (ans == INF? -1 : ans) << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



