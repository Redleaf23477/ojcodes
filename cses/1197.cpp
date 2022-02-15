#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<int,int,LL>;
constexpr LL INF = 1e18;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<Edge> edge_list(m);
    for (auto &[u, v, w] : edge_list) {
        cin >> u >> v >> w; u--, v--;
    }

    vector<LL> dist(n, INF);
    dist[0] = 0;
    for (int i = 0; i < n-1; i++) {
        for (auto &[u, v, w] : edge_list) {
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    vector<bool> relax_after_bf(m, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            auto &[u, v, w] = edge_list[j];
            if (dist[v] > dist[u] + w) {
                relax_after_bf[j] = true;
                dist[v] = dist[u] + w;
            }
        }
    }
    vector<vector<int>> neg_cycle(n);
    for (int i = 0; i < n; i++) {
        auto &[u, v, w] = edge_list[i];
        if (relax_after_bf[i]) {
            neg_cycle[u].emplace_back(v);
        }
    }
    vector<bool> vis(n, false), instk(n, false);
    vector<int> stk;
    function<bool(int)> dfs = [&](int u) {
        vis[u] = instk[u] = true;
        stk.emplace_back(u);
        for (auto v : neg_cycle[u]) {
            if (instk[v]) {
                cout << "YES\n";
                auto it = find(stk.begin(), stk.end(), v);
                while (it != stk.end()) { cout << *it + 1 << " "; it++; }
                cout << v + 1 << "\n";
                return true;
            } else if (!vis[v] && dfs(v)) {
                return true;
            }
        }
        instk[u] = false;
        stk.pop_back();
        return false;
    };
    bool found_neg_cyc = false;
    for (int i = 0; i < n && !found_neg_cyc; i++) {
        if (!vis[i]) {
            found_neg_cyc = dfs(i);
        }
    }
    if (!found_neg_cyc) {
        cout << "NO\n";
    }
}