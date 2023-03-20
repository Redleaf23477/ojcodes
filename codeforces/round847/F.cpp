#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, c0; cin >> n >> c0; c0--;
    vector<int> op(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> op[i]; op[i]--;
    }
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    vector<bool> mark(n, false);
    mark[c0] = true;
    int ans = n-1;

    vector<bool> bfs_vis(n, false);
    auto bfs = [&](int u) {
        queue<pair<int,int>> Q;
        vector<int> save;
        Q.emplace(u, 0), bfs_vis[u] = true;
        while (!Q.empty()) {
            auto [u, step] = Q.front(); Q.pop();
            if (step >= ans - 1) break;
            for (auto v : tree[u]) {
                if (mark[v]) {
                    ans = min(ans, step + 1);
                } else if (bfs_vis[v]) {
                    continue;
                } else {
                    bfs_vis[v] = true;
                    save.emplace_back(v);
                    Q.emplace(v, step + 1);
                }
            }
        }
        for (auto x : save) bfs_vis[x] = false;
    };

    for (auto x : op) {
        // cerr << "OP: " << x << endl;
        bfs(x);
        mark[x] = true;
        cout << ans << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



