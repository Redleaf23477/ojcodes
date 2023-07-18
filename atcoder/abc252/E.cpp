#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<LL,int,int>; //(w, v, idx)
constexpr LL INF = 1e18;

void solve() {
    int N, M; cin >> N >> M;
    vector<vector<Edge>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        graph[u].emplace_back(w, v, i + 1);
        graph[v].emplace_back(w, u, i + 1);
    }
    vector<int> ans;
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    vector<LL> dist(N, INF);
    dist[0] = 0, pq.emplace(0, 0, -1);
    while (!pq.empty()) {
        auto [len, u, e_idx] = pq.top(); pq.pop();
        if (dist[u] < len) continue;
        ans.emplace_back(e_idx);
        for (auto [w, v, e2] : graph[u]) {
            if (dist[v] > len + w) {
                dist[v] = len + w;
                pq.emplace(dist[v], v, e2);
            }
        }
    }
    for (size_t i = 1; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



