#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using PII = pair<int,int>;

void solve() {
    // find all diameter, then perform multisource bfs
    int n; cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    vector<int> farthest(n, 0), far_node(n, -1);
    function<PII(int,int,int)> dfs1 = [&](int u, int pa, int dep) {
        int far = u, max_dep = dep;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            auto [f, d] = dfs1(v, u, dep + 1);
            if (d > max_dep) {
                max_dep = d, far = f;
            }
        }
        farthest[u] = max(dep, max_dep - dep);
        far_node[u] = far;
        return PII(far, max_dep);
    };
    auto [x1, _] = dfs1(0, 0, 0);
    auto [x2, diam] = dfs1(x1, x1, 0);

    /*
    cerr << "x1 = " << x1 + 1 << endl;
    cerr << "x2 = " << x2 + 1 << ", diam = " << diam << endl;
    */

    // dfs2: adjust farthest
    function<void(int,int,int)> dfs2 = [&](int u, int pa, int dep) {
        farthest[u] = dep;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            if (far_node[v] == x2) continue;
            dfs2(v, u, dep + 1);
        }
    };
    for (int x3 = 0; x3 < n; x3++) {
        if (far_node[x3] == x2) {
            dfs2(x3, x3, farthest[x3]);
        }
    }

    /*
    for (int i = 0; i < n; i++) {
        cerr << i + 1 << " : " << farthest[i] << endl;
    }
    */

    vector<vector<int>> re_far(diam + 1);
    for (int i = 0; i < n; i++) {
        re_far[farthest[i]].emplace_back(i);
    }

    //////////////////////////////////////
    
    queue<int> now, next;
    vector<bool> vis(n, false);
    vector<int> ans(n, n);
    int cc = n + 1;
    auto step_bfs = [&]() {
        while (!now.empty()) {
            auto u = now.front(); now.pop();
            cc--;
            for (auto v : graph[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    next.emplace(v);
                }
            }
        }
    };
    for (int d = diam; d > 0; d--) {
        // run one iteration of bfs
        for (auto x : re_far[d]) {
            if (!vis[x]) {
                now.emplace(x), vis[x] = true;
            }
        }
        step_bfs();
        ans[d-1] = cc;
        swap(now, next);
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



