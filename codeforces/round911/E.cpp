#include <bits/stdc++.h>
using namespace std;
using LL = long long;

bool cmp(pair<int,LL> const &lhs, pair<int,LL> const &rhs) {
    if (lhs.first != rhs.first) return lhs.first < rhs.first;
    else return lhs.second > rhs.second;
}

struct Kosaraju {
    vector<vector<int>> &graph;
    vector<int> &scc_idx;
    vector<vector<int>> &scc_graph;
    vector<int> &scc_node_size;

    vector<vector<int>> inv_graph;

    Kosaraju(vector<vector<int>> &_graph, vector<int> &_scc_idx, vector<vector<int>> &_scc_graph, vector<int> &_scc_node_size)
        : graph(_graph), scc_idx(_scc_idx), scc_graph(_scc_graph), scc_node_size(_scc_node_size), inv_graph(graph.size()) {
        for (int u = 0; u < (int)graph.size(); u++) {
            for (auto v : graph[u]) {
                inv_graph[v].emplace_back(u);
            }
        }
    }

    void run() {
        int n = graph.size();
        vector<bool> vis;
        vector<int> order;
        function<void(int)> dfs1 = [&](int u) {
            vis[u] = true;
            for (auto v : graph[u]) {
                if (!vis[v]) dfs1(v);
            }
            order.emplace_back(u);
        };
        function<void(int, int)> dfs2 = [&](int u, int s) {
            scc_idx[u] = s;
            vis[u] = true;
            for (auto v : inv_graph[u]) {
                if (!vis[v]) {
                    dfs2(v, s);
                }
            }
        };

        vis.assign(n, false);
        for (int u = 0; u < n; u++) {
            if (!vis[u]) {
                dfs1(u);
            }
        }
        reverse(order.begin(), order.end());
        vis.assign(n, false);
        int scc_num = 0;
        for (auto u : order) {
            if (!vis[u]) {
                dfs2(u, scc_num++);
            }
        }

        scc_graph.assign(scc_num, vector<int>());
        scc_node_size.assign(scc_num, 0);
        for (int u = 0; u < n; u++) {
            scc_node_size[scc_idx[u]] += 1;
            for (auto v : graph[u]) {
                if (scc_idx[u] != scc_idx[v]) {
                    scc_graph[scc_idx[u]].emplace_back(scc_idx[v]);
                }
            }
        }
    }
};

void dag_longest_path(vector<vector<int>> &graph, vector<LL> &val, vector<int> &sz, int n) {
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; u++) {
        for (auto v : graph[u]) {
            indeg[v] += 1;
        }
    }

    vector<pair<int,LL>> path(n, {0, 0});
    queue<int> Q;
    for (int u = 0; u < n; u++) {
        if (indeg[u] == 0) {
            Q.emplace(u);
            path[u] = make_pair(sz[u], val[u]);
        }
    }

    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto v : graph[u]) {
            path[v] = max(path[v], pair<int,LL>(path[u].first + sz[v], path[u].second + val[v]), cmp);
            if (--indeg[v] == 0) {
                Q.emplace(v);
            }
        }
    }

    auto [len, sum] = *max_element(path.begin(), path.end(), cmp);
    cout << len << " " << sum << "\n";
}

void solve() {
    int n, m; cin >> n >> m;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        if (u == v) continue;
        graph[u].emplace_back(v);
    }

    vector<int> scc_idx(n);
    vector<vector<int>> scc_graph;
    vector<int> scc_node_size;
    Kosaraju(graph, scc_idx, scc_graph, scc_node_size).run();

    /*
    for (int i = 0; i < n; i++) {
        cerr << "i = " << i + 1 << ", scc_idx = " << scc_idx[i] << endl;
    }
    for (int u = 0; u < (int)scc_graph.size(); u++) {
        for (auto v : scc_graph[u]) {
            cerr << "edge " << u << " " << v << endl;
        }
    }
    cerr << "scc_node_size = ";
    for (auto sz : scc_node_size) cerr << sz << " ";
    cerr << endl;
    */
    
    int sn = scc_graph.size();
    vector<LL> scc_node_val(sn, 0);
    for (int i = 0; i < n; i++) {
        scc_node_val[scc_idx[i]] += arr[i];
    }

    dag_longest_path(scc_graph, scc_node_val, scc_node_size, sn);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

