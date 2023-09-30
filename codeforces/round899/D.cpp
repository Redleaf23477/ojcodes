#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int B = 20;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    vector<int> size(n, 0);
    // make_bit[subtree at v][i-th bit][0 or 1] = cost
    vector<vector<vector<LL>>> make_bit(n, vector<vector<LL>>(B, vector<LL>(2, 0)));

    function<void(int,int)> dfs1 = [&](int u, int pa) {
        size[u] += 1;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dfs1(v, u);
            size[u] += size[v];
        }
        for (int b = 0; b < B; b++) for (int bit : {0, 1}) {
            int mybit = (arr[u] >> b) & 1;
            int flip = mybit != bit;
            for (auto v : tree[u]) {
                make_bit[u][b][bit] += make_bit[v][b][flip ^ bit];
            }
            make_bit[u][b][bit] += flip * (1ll << b) * size[u];
        }
    };
    dfs1(0, 0);
    /*
    LL ans = 0;
    for (int i = 0; i < B; i++) {
        ans += min(make_bit[0][i][0], make_bit[0][i][1]);
    }
    cout << ans << "\n";
    */

    auto change_root = [&](int u, int v) {
        for (int b = 0; b < B; b++) for (int bit : {0, 1}) {
            int u_flip = ((arr[u] >> b) & 1) != bit;
            make_bit[u][b][bit] -= u_flip * (1ll << b) * size[u];
            make_bit[u][b][bit] -= make_bit[v][b][u_flip ^ bit];
        }
        for (int b = 0; b < B; b++) for (int bit : {0, 1}) {
            int v_flip = ((arr[v] >> b) & 1) != bit;
            make_bit[v][b][bit] -= v_flip * (1ll << b) * size[v];
        }
        size[u] -= size[v], size[v] += size[u];
        for (int b = 0; b < B; b++) for (int bit : {0, 1}) {
            int u_flip = ((arr[u] >> b) & 1) != bit;
            make_bit[u][b][bit] += u_flip * (1ll << b) * size[u];
        }
        for (int b = 0; b < B; b++) for (int bit : {0, 1}) {
            int v_flip = ((arr[v] >> b) & 1) != bit;
            make_bit[v][b][bit] += make_bit[u][b][v_flip ^ bit];
            make_bit[v][b][bit] += v_flip * (1ll << b) * size[v];
        }
    };

    vector<LL> ans(n, 0);
    function<void(int,int)> dfs2 = [&](int u, int pa) {
        // calculate my answer
        for (int b = 0; b < B; b++) {
            ans[u] += min(make_bit[u][b][0], make_bit[u][b][1]);
        }
        // change root
        for (auto v : tree[u]) {
            if (v == pa) continue;
            // update & run
            change_root(u, v);
            dfs2(v, u);
            // restore
            change_root(v, u);
        }
    };
    dfs2(0, 0);

    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

