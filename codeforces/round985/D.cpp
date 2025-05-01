#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// step 1: remove every cycle
//          --> now graph is a forest
// step 2: connect every tree

vector<tuple<int,int>> reorg(vector<set<int>> &graph) {
    vector<tuple<int,int>> edges;
    int vn = graph.size();
    for (int u = 0; u < vn; u++) {
        for (auto v : graph[u]) {
            if (u < v) edges.emplace_back(u, v);
        }
    }
    return edges;
}

void solve() {
    int vn, en; cin >> vn >> en;
    vector<set<int>> graph(vn);
    for (int e = 0; e < en; e++) {
        int u, v; cin >> u >> v; u--, v--;
        if (u > v) swap(u, v);
        graph[u].insert(v);
        graph[v].insert(u);
    }

    vector<tuple<int,int,int>> operations;
    auto do_operation = [&](int a, int b, int c) {
        operations.emplace_back(a, b, c);
    };

    // phase 1: remove all deg-2 nodes
    for (int u = 0; u < vn; u++) {
        while (graph[u].size() > 1) {
            int x = *graph[u].begin(); graph[u].erase(graph[u].begin());
            int y = *graph[u].begin(); graph[u].erase(graph[u].begin());
            do_operation(u, x, y);
            graph[x].erase(u);
            graph[y].erase(u);
            if (graph[x].count(y) == 0) graph[x].insert(y);
            else graph[x].erase(y);
            if (graph[y].count(x) == 0) graph[y].insert(x);
            else graph[y].erase(x);
        }
    }

    // phase 1.5: re-org graph
    auto edges = reorg(graph);
    
    // phase 2: connect the trees
    vector<bool> vis(vn, false);
    function<void(int)> dfs2 = [&](int u) {
        vis[u] = true;
        for (auto v : graph[u]) {
            if (!vis[v]) dfs2(v);
        }
    };
    if (edges.size() != 0) {
        vis.assign(vn, false);
        auto [root, buddy] = edges[0];
        dfs2(root);
        for (int i = 0; i < vn; i++) {
            if (!vis[i]) {
                dfs2(i);
                do_operation(root, buddy, i);
                buddy = i;
            }
        }
    }

    // print answer
    cout << operations.size() << "\n";
    for (auto [a, b, c] : operations) {
        cout << a + 1 << " " << b + 1 << " " << c + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

