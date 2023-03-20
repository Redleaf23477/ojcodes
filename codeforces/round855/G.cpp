#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }

    map<vector<int>,int> tree_map;
    vector<bool> is_subtree_sym(n, false);

    auto check_sym = [&](vector<int> &subtree_key, vector<int> &child, int pa) {
        map<int,int> cnt;
        set<int> has_sym;
        for (size_t i = 0, j = 0; i < child.size(); i++) {
            int v = child[i];
            if (v == pa) continue;
            cnt[subtree_key[j]]++;
            if (is_subtree_sym[v]) {
                has_sym.insert(subtree_key[j]);
            }
            j++;
        }
        bool is_sym = true, mid_used = false;
        subtree_key.clear();
        for (auto [key, num] : cnt) {
            subtree_key.insert(subtree_key.end(), num, key);
            if (num % 2 == 1) {
                if (has_sym.count(key) == 0) {
                    is_sym = false;
                } else if (mid_used) {
                    is_sym = false;
                } else {
                    mid_used = true;
                }
            }
        }
        return is_sym;
    };

    function<int(int,int)> dfs = [&](int u, int pa) {
        vector<int> subtree_key;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            subtree_key.emplace_back(dfs(v, u));
        }
        is_subtree_sym[u] = check_sym(subtree_key, graph[u], pa);
        if (tree_map.count(subtree_key) == 0) {
            int idx = tree_map.size();
            tree_map[subtree_key] = idx;
        }
        return tree_map[subtree_key];
    };

    dfs(0, 0);
    if (is_subtree_sym[0]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



