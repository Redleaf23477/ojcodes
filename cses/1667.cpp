#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void bfs(const vector<vector<int>> &graph) {
    int DEST = graph.size() - 1;
    vector<int> backtrack(graph.size(), -1);
    queue<int> q({0}); backtrack[0] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : graph[u]) {
            if (backtrack[v] != -1) continue;
            backtrack[v] = u;
            q.emplace(v);
        }
    }
    if (backtrack[DEST] == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int> ans {DEST};
        while (DEST != backtrack[DEST]) {
            ans.emplace_back(backtrack[DEST]);
            DEST = backtrack[DEST];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto x : ans) cout << x + 1 << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    bfs(graph);
}

