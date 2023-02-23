#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Bset = bitset<50000>;

struct Kosaraju {
    int n;
    vector<vector<int>> &graph;
    vector<vector<int>> rev;
    Kosaraju(vector<vector<int>> &_graph) : n(_graph.size()), graph(_graph), rev(n) {
        for (int i = 0; i < n; i++) for (auto j : graph[i]) {
            rev[j].emplace_back(i);
        }
    }
    void run(vector<vector<int>> &condensed_graph, vector<int> &sccidx) {
        stack<int> out_vertex;
        vector<bool> vis(n, false);
        // first dfs: sort by out time
        function<void(int)> dfs1 = [&](int u) {
            vis[u] = true;
            for (auto v : graph[u]) {
                if (!vis[v]) dfs1(v);
            }
            out_vertex.emplace(u);
        };
        for (int i = 0; i < n; i++) {
            if (!vis[i]) dfs1(i);
        }
        // second dfs: find scc
        function<void(int,int)> dfs2 = [&](int u, int scc) {
            vis[u] = true;
            sccidx[u] = scc;
            for (auto v : rev[u]) {
                if (!vis[v]) dfs2(v, scc);
            }
        };
        int scc;
        fill(vis.begin(), vis.end(), false);
        for (scc = 0; !out_vertex.empty(); out_vertex.pop()) {
            if (!vis[out_vertex.top()]) {
                dfs2(out_vertex.top(), scc);
                scc++;
            }
        }
        // build condensed graph
        condensed_graph.assign(scc, vector<int>());
        for (int u = 0; u < n; u++) {
            for (auto v : graph[u]) {
                int u_scc = sccidx[u], v_scc = sccidx[v];
                if (u_scc != v_scc) {
                    condensed_graph[u_scc].emplace_back(v_scc);
                }
            }
        }
    }
};

void toposort(vector<vector<int>> const &graph, vector<Bset> &decendents) {
    int n = graph.size();
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        decendents[u][u] = true;
        for (auto v : graph[u]) {
            if (!vis[v]) dfs(v);
            decendents[u] |= decendents[v];
        }
    };
    for (int u = 0; u < n; u++) {
        if (!vis[u]) dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
    }

    vector<vector<int>> condensed_graph;
    vector<int> sccidx(n);
    Kosaraju(graph).run(condensed_graph, sccidx);

    vector<Bset> decendents(condensed_graph.size(), 0);
    toposort(condensed_graph, decendents);

    while (q--) {
        int u, v; cin >> u >> v; u--, v--;
        int u_scc = sccidx[u], v_scc = sccidx[v];
        if (u_scc == v_scc) cout << "YES\n";
        else if (decendents[u_scc][v_scc]) cout << "YES\n";
        else cout << "NO\n";
    }
}

