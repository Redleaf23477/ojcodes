#include <bits/stdc++.h>
#include <queue>
using namespace std;
using LL = long long;
using P = pair<LL, int>; // (cost, index)

void solve() {
    int N, M; cin >> N >> M;
    vector<LL> A(N);
    for (auto &x : A) cin >> x;
    vector<LL> cost(N, 0);
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        cost[u] += A[v];
        cost[v] += A[u];
    }
    priority_queue<P, vector<P>, greater<P>> pq;
    for (int i = 0; i < N; i++) {
        pq.emplace(cost[i], i);
    }

    LL ans = 0;
    vector<bool> bye(N, false);
    while (!pq.empty()) {
        auto [c, u] = pq.top(); pq.pop();
        if (bye[u]) continue;
        bye[u] = true;
        ans = max(ans, c);
        for (auto v : graph[u]) {
            cost[v] -= A[u];
            pq.emplace(cost[v], v);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}