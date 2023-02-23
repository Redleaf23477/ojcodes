#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    vector<int> sz(n, -1), ans(n, -1);
    function<void(int)> dfs1 = [&](int u) {
        sz[u] = 1;
        for (auto v : graph[u]) {
            if (A[u] > A[v]) {
                if (sz[v] == -1) dfs1(v);
                sz[u] += sz[v];
            }
        }
    };

    function<void(int,int)> dfs2 = [&](int u, int pa) {
        // count unvisited tree size
        dfs1(u);
        // update answer
        ans[u] = sz[u];
        // change root
        for (auto v : graph[u]) if (v != pa) {
            dfs2(v, u);
        }
    };
    dfs2(0, 0);

    cout << *max_element(ans.begin(), ans.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

