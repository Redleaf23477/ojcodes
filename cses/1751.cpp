#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        graph[x].emplace_back(i);
    }

    // dfs1 find cycle
    vector<int> cycle_idx(n, -1), cycle_size;
    vector<bool> vis(n, false), instk(n, false);
    vector<int> stk;
    function<void(int)> dfs = [&](int u) {
        vis[u] = instk[u] = true, stk.emplace_back(u);
        for (auto v : graph[u]) {
            if (instk[v]) {
                // report cycle
                auto it = find(stk.begin(), stk.end(), v);
                int sz = stk.end() - it;
                for (int i = 0; it != stk.end(); it++, i++) {
                    cycle_idx[*it] = cycle_size.size();
                }
                cycle_size.emplace_back(sz);
            } else if (!vis[v]) {
                dfs(v);
            }
        }
        instk[u] = false, stk.pop_back();
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i]) dfs(i);
    }

    // dfs2 find answer
    vector<int> dep(n, -1), rt(n, -1);
    vis.assign(n, false);
    function<void(int,int,int)> dfs2 = [&](int u, int d, int cyc) {
        vis[u] = true, rt[u] = cyc;
        if (cycle_idx[u] != -1) d = 0;
        dep[u] = d;
        for (auto v : graph[u]) {
            if (!vis[v]) dfs2(v, d + 1, cyc);
        }
    };

    for (int i = 0; i < n; i++) {
        if (!vis[i] && cycle_idx[i] != -1) {
            dfs2(i, 0, cycle_idx[i]);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << dep[i] + cycle_size[rt[i]] << " ";
    }
    cout << "\n";
}

