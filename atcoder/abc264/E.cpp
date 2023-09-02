#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, M, E; cin >> N >> M >> E;
    vector<vector<int>> graph(N + 1);
    vector<pair<int,int>> edge(E);
    for (auto &[u, v] : edge) {
        cin >> u >> v; u--, v--;
        if (u >= N) u = N;
        if (v >= N) v = N;
    }
    vector<bool> undead(E, true);
    int Q; cin >> Q;
    vector<int> event(Q);
    for (auto &e : event) {
        cin >> e; e--;
        undead[e] = false;
    }
    for (int i = 0; i < E; i++) {
        if (undead[i]) {
            auto [u, v] = edge[i];
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
    }
    vector<bool> electrified(N + 1, false);
    electrified[N] = true;
    vector<int> ans(Q + 1, 0);
    function<int(int)> dfs = [&](int u) {
        int ans = 0;
        electrified[u] = true;
        ans++;
        for (auto v : graph[u]) {
            if (!electrified[v]) {
                ans += dfs(v);
            }
        }
        graph[u].clear();
        return ans;
    };
    ans[Q] = dfs(N) - 1;
    for (int q = Q - 1; q >= 0; q--) {
        ans[q] = ans[q + 1];

        auto [u, v] = edge[event[q]];
        if (electrified[u]) u = N;
        if (electrified[v]) v = N;
        if (u == v) continue;

        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        ans[q] += dfs(N) - 1;
    }
    for (int i = 1; i <= Q; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



