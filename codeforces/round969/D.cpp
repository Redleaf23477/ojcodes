#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Solver {
    vector<vector<size_t>> &tree;
    string color;

    Solver(vector<vector<size_t>> &t, string &c) : tree(t), color(c) {}

    size_t path_cnt[3];  // [0, 1]: end with 0, 1; [2]: end with ?
    size_t trash_cnt;
    void check_tree() {
        memset(path_cnt, 0, sizeof(path_cnt));
        trash_cnt = 0;
        dfs(0, 0);
    }
    void dfs(size_t u, size_t pa) {
        if (tree[u].size() == 1 && u != 0) {
            // is leaf
            if (color[u] == '?') path_cnt[2] ++;
            else path_cnt[color[u] - '0']++;
            return;
        } else if (u != 0) {
            // non-root internal
            if (color[u] == '?') trash_cnt++;
        }
        // dfs
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dfs(v, u);
        }
    }

    size_t cal_ans() {
        // case 1: root is colored
        if (color[0] != '?') {
            return path_cnt[1 - (color[0] - '0')] + path_cnt[2] / 2 + path_cnt[2] % 2;
        }

        // case 2: root is uncolored
        // case 2.1: path_cnt[0] != path_cnt[1], then color root first
        if (path_cnt[0] != path_cnt[1]) {
            return max(path_cnt[0], path_cnt[1]) + path_cnt[2] / 2;
        }

        // case 2.2: color trash first
        if (trash_cnt % 2 == 0) {
            return path_cnt[0] + path_cnt[2] / 2;
        } else {
            return path_cnt[0] + path_cnt[2] / 2 + path_cnt[2] % 2;
        }
    }
};

void solve() {
    size_t n; cin >> n;
    vector<vector<size_t>> tree(n);
    for (size_t i = 1; i < n; i++) {
        size_t u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    string color; cin >> color;

    Solver s(tree, color);
    s.check_tree();
    cout << s.cal_ans() << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

