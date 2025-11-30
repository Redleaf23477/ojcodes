#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    constexpr LL MOD = 998244353;
    size_t n, m, k; cin >> n >> m >> k;
    vector<tuple<size_t, size_t>> edges(m);
    for (auto &[u, v] : edges) {
        cin >> u >> v; u--, v--;
    }
    sort(edges.begin(), edges.end());

    vector<LL> path(n, 0);
    path[0] = 1;
    for (size_t _ = 0; _ < k; _++) {
        // step: m edges
        map<size_t, LL> updates;
        for (auto [u, v] : edges) {
            if (updates.count(v) == 0) {
                updates[v] = 0;
            }
            updates[v] += path[u];
        }

        // step: shift edges
        for (auto &[u, v] : edges) {
            u = (u == 0? n - 1 : u - 1);
            v = (v == 0? n - 1 : v - 1);
        }

        // step: update path
        for (auto [u, upd] : updates) {
            int v = (u == 0? n - 1 : u - 1);
            path[v] = (path[v] + upd) % MOD;
        }
    }

    LL ans = 0;
    for (auto p : path) ans = (ans + p) % MOD;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

