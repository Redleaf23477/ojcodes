#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
    }

    vector<int> ans({0});
    vector<bool> vis(n, false), watch_list(n, false);
    vector<int> indeg(n, 0);
    int watch_cnt = 0;
    queue<int> q;
    vis[0] = true; q.emplace(0);
    watch_list[0] = true, watch_cnt += 1;
    for (auto v : graph[0]) {
        watch_list[v] = true, watch_cnt += 1;
        indeg[v] += 1;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        watch_cnt -= 1, watch_list[u] = false;
        if (watch_cnt == 0) ans.emplace_back(u);
        for (auto v : graph[u]) {
            if (vis[v]) continue;
            if (!watch_list[v]) {
                watch_list[v] = true, watch_cnt += 1;
            }
            if (--indeg[v] == 0) {
                for (auto k : graph[v]) {
                    indeg[k]++;
                }
                vis[v] = true;
                q.emplace(v);
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto x : ans) cout << x + 1 << " ";
    cout << "\n";
}

