#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> fri(k);
    for (auto &x : fri) {
        cin >> x; x--;
    }
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    const int INF = 2*n;

    vector<int> dist(n, 2*n);
    // bfs from friends
    queue<int> q;
    for (auto x : fri) {
        q.emplace(x);
        dist[x] = 0;
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : tree[u]) {
            if (dist[v] != INF) continue;
            dist[v] = dist[u] + 1;
            q.emplace(v);
        }
    }

    // dfs from root
    function<bool(int,int,int)> dfs = [&](int u, int pa, int d) {
        if (dist[u] <= d) return false;
        if (tree[u].size() == 1 && u != 0) {
            return true;
        }
        bool ans = false;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            ans = ans || dfs(v, u, d+1);
        }
        return ans;
    };
    if (dfs(0, 0, 0)) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

