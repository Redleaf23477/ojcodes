#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<int,int,LL>;  // (u, v, w)

constexpr LL INF = 1e18;

void mark(int s, vector<bool> &neg, const vector<Edge> &edge_list, bool rev) {
    int n = neg.size();
    vector<vector<int>> graph(n); 
    for (auto [u, v, w] : edge_list) {
        if (rev) {
            graph[v].emplace_back(u);
        } else {
            graph[u].emplace_back(v);
        }
    }
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v : graph[u]) {
            if (vis[v]) continue;
            dfs(v);
        }
    };
    dfs(s);
    for (int i = 0; i < n; i++) {
        neg[i] = neg[i] && vis[i];
    }
}

void solve() {
    int n, m; cin >> n >> m;
    vector<LL> dist(n, INF);
    vector<Edge> edge_list(m);
    for (auto &[u, v, w] : edge_list) {
        cin >> u >> v >> w; u--, v--, w *= -1;
    }
    dist[0] = 0;

    // bellman ford
    auto relax = [&](int u, int v, LL w) {
        if (dist[v] > dist[u] + w) {
            dist[v] = dist[u] + w;
            return true;
        } else {
            return false;
        }
    };
    for (int i = 0; i < n-1; i++) {
        for (auto [u, v, w] : edge_list) {
            relax(u, v, w);
        }
    }
    vector<bool> neg(n, false);
    for (auto [u, v, w] : edge_list) {
        if (relax(u, v, w)) {
            neg[u] = neg[v] = true;
        }
    }
    
    // if 0 --> neg[v] --> n-1 then gg
    mark(0, neg, edge_list, false);
    mark(n-1, neg, edge_list, true);
    for (int i = 0; i < n; i++) {
        if (neg[i]) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << -dist[n-1] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    solve();
}
