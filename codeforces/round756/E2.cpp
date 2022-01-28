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
    function<pair<bool,int>(int,int,int)> dfs = [&](int u, int pa, int d) {
        if (dist[u] <= d) return make_pair(false, 1);
        if (tree[u].size() == 1 && u != 0) {
            return make_pair(true, 0);
        }
        bool ac = false;
        int cnt = 0;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            auto [sub_ac, sub_cnt] = dfs(v, u, d+1);
            ac = ac || sub_ac;
            cnt += sub_cnt;
        }
        return make_pair(ac, cnt);
    };
    auto [ac, cnt] = dfs(0, 0, 0);
    if (ac) {
        cout << -1 << "\n";
    } else {
        cout << cnt << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

