#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<int>> g1(n); {
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v; u--, v--;
            g1[u].emplace_back(v);
            g1[v].emplace_back(u);
        }
    }
    vector<vector<int>> g2(n); {
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v; u--, v--;
            g2[u].emplace_back(v);
            g2[v].emplace_back(u);
        }
    }
    vector<int> perm(n); {
        iota(perm.begin(), perm.end(), 0);
    }

    vector<bool> vis1(n), vis2(n);
    function<bool(int,int)> dfs = [&](int u1, int u2) {
        if (vis2[u2]) return false;
        vis1[u1] = vis2[u2] = true;
        bool good = true;
        for (auto v1 : g1[u1]) {
            int v2 = perm[v1];
            if (!vis1[v1]) {
                if (find(g2[u2].begin(), g2[u2].end(), perm[v1]) == g2[u2].end()) {
                    good = false;
                } else {
                    good = good && dfs(v1, v2);
                }
            }
        }
        return good;
    };

    bool possible = false;
    do {
        possible = true;
        for (int i = 0; i < n; i++) {
            if (g1[i].size() != g2[perm[i]].size()) possible = false;
        }
        if (!possible) continue;
        vis1.assign(n, false), vis2.assign(n, false);
        for (int i = 0; i < n && possible; i++) {
            if (!vis1[i]) possible = possible && dfs(i, perm[i]);
        }
    } while (!possible && next_permutation(perm.begin(), perm.end()));
    cout << (possible? "Yes" : "No") << endl;
}