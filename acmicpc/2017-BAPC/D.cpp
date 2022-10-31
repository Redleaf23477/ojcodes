#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<LL,int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        graph[u].emplace_back(w, v);
        graph[v].emplace_back(w, u);
    }
    // dijk
    vector<int> sp_pa(n, -1);
    vector<LL> dist(n, 1e18);
    priority_queue<Edge, vector<Edge>, greater<Edge>> PQ;
    PQ.emplace(0, 1), dist[1] = 0, sp_pa[1] = 1;
    while (!PQ.empty()) {
        auto [len, u] = PQ.top(); PQ.pop();
        if (len > dist[u]) continue;
        for (auto [w, v] : graph[u]) {
            LL new_len = len + w;
            if (dist[v] > new_len) {
                dist[v] = new_len;
                sp_pa[v] = u;
                PQ.emplace(new_len, v);
            }
        }
    }
    // bfs
    vector<int> bfs_pa(n, -1);
    queue<int> Q;
    Q.emplace(0), bfs_pa[0] = 0;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto [w, v] : graph[u]) {
            if (bfs_pa[v] != -1) continue;
            if (sp_pa[u] == v) continue;
            bfs_pa[v] = u;
            Q.emplace(v);
        }
    }
    // print answer
    if (bfs_pa[1] == -1) {
        cout << "impossible\n";
    } else {
        vector<int> answer;
        for (int v = 1; v != 0; v = bfs_pa[v]) {
            answer.emplace_back(v);
        }
        reverse(answer.begin(), answer.end());
        cout << answer.size() + 1;
        cout << " " << 0;
        for (auto x : answer) cout << " " << x;
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}

