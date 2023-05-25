#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        // parent -> child
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
    }
    vector<int> give(n), is_given(n, 0);
    for (auto &x : give) {
        cin >> x; x--;
        is_given[x]++;
    }

    // mark depth
    vector<int> depth(n, -1);
    function<void(int,int)> dfs1 = [&](int u, int dep) {
        depth[u] = dep;
        for (auto v : graph[u]) {
            dfs1(v, dep + 1);
        }
    };
    vector<int> roots;
    for (int i = 0; i < n; i++) {
        if (depth[i] == -1) {
            roots.emplace_back(i);
            dfs1(i, 0);
        }
    }

    // build dag
    vector<vector<int>> dag(n);
    // build down edges
    function<int(int,int)> dfs2 = [&](int u, int pa) {
        int back_dep = depth[give[u]];
        for (auto v : graph[u]) {
            int d = dfs2(v, u);
            back_dep = min(back_dep, d);
        }
        if (u != pa && back_dep < depth[u]) {
            dag[pa].emplace_back(u);
        }
        return back_dep;
    };
    // build up edges
    function<list<int>(int,int)> dfs3 = [&](int u, int pa) {
        list<int> ret;
        for (auto v : graph[u]) {
            ret.splice(ret.end(), dfs3(v, u));
        }
        if (is_given[u] != 0) {
            for (auto x : ret) {
                dag[x].emplace_back(u);
            }
            ret = list<int> {u};
        }
        return ret;
    };
    for (auto r : roots) {
        dfs2(r, r);
        dfs3(r, r);
    }

    /*
    cerr << "DAG: " << endl;
    for (int i = 0; i < n; i++) {
        cerr << i + 1 << " : ";
        for (auto v : dag[i]) cerr << v + 1 << " ";
        cerr << endl;
    }
    */

    // the answer is a topological order
    auto topo_sort = [](vector<vector<int>> const &dag, int n) {
        vector<int> indeg(n, 0);
        for (int u = 0; u < n; u++) {
            for (auto v : dag[u]) {
                indeg[v]++;
            }
        }
        queue<int> Q;
        for (int u = 0; u < n; u++) {
            if (indeg[u] == 0) Q.emplace(u);
        }
        vector<int> ans;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            ans.emplace_back(u);
            for (auto v : dag[u]) {
                if (--indeg[v] == 0) {
                    Q.emplace(v);
                }
            }
        }
        return ans;
    };
    vector<int> topo_order = topo_sort(dag, n);
    if (topo_order.size() == n) {
        cout << topo_order.size() << "\n";
        for (auto x : topo_order) cout << x + 1 << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



