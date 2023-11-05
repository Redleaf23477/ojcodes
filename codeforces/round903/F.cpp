#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> is_marked(n, false);
    for (int i = 0; i < k; i++) {
        int x; cin >> x; x--;
        is_marked[x] = true;
    }
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    vector<vector<int>> far(n);
    function<void(int,int)> dfs1 = [&](int u, int pa) {
        if (is_marked[u]) far[u].emplace_back(0);
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dfs1(v, u);
            if (!far[v].empty()) {
                far[u].emplace_back(far[v].front() + 1);
            }
            if (far[u].size() >= 1) {
                swap(far[u][0], *max_element(far[u].begin(), far[u].end()));
            }
            if (far[u].size() >= 2) {
                swap(far[u][1], *max_element(far[u].begin() + 1, far[u].end()));
                far[u].erase(far[u].begin() + 2, far[u].end());
            }
        }
    };
    dfs1(0, 0);

    /*
    cerr << "far = ";
    for (int i = 0; i < n; i++) {
        cerr << "(";
        for (auto x : far[i]) cerr << x << " ";
        cerr << ")";
    }
    cerr << endl;
    */

    int ans = n;
    function<void(int,int)> dfs2 = [&](int u, int pa) {
        if (!far[u].empty()) {
            // cerr << "u = " << u << ", far[u][0] = " << far[u][0] << endl;
            ans = min(ans, far[u][0]);
        }
        for (auto v : tree[u]) {
            if (v == pa) continue;
            auto backup_u = far[u], backup_v = far[v];
            if (!far[u].empty() && !far[v].empty() && far[u][0] == far[v][0] + 1) {
                far[u].erase(far[u].begin());
            }
            if (!far[u].empty()) {
                far[v].emplace_back(far[u].front() + 1);
                if (far[v].size() >= 1) {
                    swap(far[v][0], *max_element(far[v].begin(), far[v].end()));
                }
                if (far[v].size() >= 2) {
                    swap(far[v][1], *max_element(far[v].begin() + 1, far[v].end()));
                    far[v].erase(far[v].begin() + 2, far[v].end());
                }
            }
            dfs2(v, u);
            far[u] = backup_u, far[v] = backup_v;
        }
    };
    dfs2(0, 0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

