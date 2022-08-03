#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<vector<int>> graph(1'000'000);
vector<int> root_path(1'000'000);

void dfs(int u, int pa, int path) {
    root_path[u] = min(u, path);
    for (auto v : graph[u]) {
        if (v == pa) continue;
        dfs(v, u, root_path[u]);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int e = 0; e < n-1; e++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    // root
    int op, x, last = 0; cin >> op >> x;
    x = (x + last) % n;  // 0-based
    dfs(x, x, x);
    // start query
    int global_min = n;
    for (int _q = 1; _q < q; _q++) {
        cin >> op >> x;
        x = (x + last) % n;  // 0-based
        assert(0 <= x && x < n);
        if (op == 1) {
            global_min = min(global_min, root_path[x]);
        } else {
            // query
            last = min(root_path[x], global_min) + 1;
            cout << last << "\n";
        }
    }
}

