#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Solver {
    int n, k;
    vector<vector<int>> &tree;
    vector<bool> &dest1, &dest2;
    vector<bool> has1, has2;
    vector<int> dep;
    int ans;
    Solver(int _n, int _k, vector<vector<int>> &_tree, vector<bool> &d1, vector<bool> &d2) : 
        n(_n), k(_k), tree(_tree), 
        dest1(d1), dest2(d2), 
        has1(n, false), has2(n, false), 
        dep(n, 0), ans(0) {
    }
    void dfs1(int u, int pa) {
        if (dest1[u]) has1[u] = true;
        if (dest2[u]) has2[u] = true;
        for (auto v : tree[u]) {
            if (v != pa) {
                dep[v] = dep[u] + 1;
                dfs1(v, u);
                if (has1[v]) has1[u] = true;
                if (has2[v]) has2[u] = true;
            }
        }
    }
    int d1, d2;
    void dfs2(int u, int pa) {
        // enter, move 1 and 2, update answer
        if (has1[u]) {
            ans += d1;
            d1 = 0;
        }
        if (has2[u]) {
            ans += d2;
            d2 = 0;
        }
        if (d1 > k) {
            ans++;
            d1--;
        }
        if (d2 > k) {
            ans++;
            d2--;
        }
        // cerr << "u = " << u << ", d1 = " << d1 << ", d2 = " << d2 << ", ans = " << ans << endl;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            if (has1[v] || has2[v]) {
                d1++, d2++;
                dfs2(v, u);
                // cerr << "u = " << u << ", d1 = " << d1 << ", d2 = " << d2 << ", ans = " << ans << endl;
            }
        }
        // leave, move 1 and 2, update answer
        if (u != 0) {
            if (d1 == 0) {
                ans++;
            } else {
                d1--;
            }
            if (d2 == 0) {
                ans++;
            } else {
                d2--;
            }
        }
    }
    int solve() {
        // mark has1, has2
        dfs1(0, 0);
        // traverse
        d1 = d2 = 0;
        dfs2(0, 0);
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    vector<bool> dest1(n, false), dest2(n, false);
    int x; cin >> x;
    while (x--) {
        int y; cin >> y; dest1[y-1] = true;
    }
    cin >> x;
    while (x--) {
        int y; cin >> y; dest2[y-1] = true;
    }
    cout << Solver(n, k, tree, dest1, dest2).solve() << "\n";
}

