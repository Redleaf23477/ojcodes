#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct Solver {
    int n, k;
    vector<vector<int>> tree;
    vector<int> color;
    vector<int> exception_table;
    Solver(int _n, vector<vector<int>> _t) : n(_n), tree(_t) {
        run();
    }
    void run() {
        bool res = special();
        if (res) return;
        res = normal();
    }
    bool special() {
        color.assign(n, -1);
        exception_table.assign(3, -1);
        exception_table[0] = 1;
        exception_table[1] = 0;
        for (int i = 1; i < n; i++) {
            if (tree[i].size() == 2) {
                if (!dfs_special(i, i, 0)) {
                    return false;
                }
            }
        }
        dfs_remain(0, 0, 1);
        k = *max_element(color.begin() + 1, color.end()) + 1;
        return true;
    }
    bool dfs_special(int u, int pa, int pa_color) {
        if (u == 0) return true;
        color[u] = pa_color;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            if (color[v] == -1) {
                if (!dfs_special(v, u, 1 - pa_color)) {
                    return false;
                }
            } else if (color[v] == color[u]) {
                return false;
            }
        }
        return true;
    }
    void dfs_remain(int u, int pa, int pa_color) {
        color[u] = pa_color;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            if (color[v] != -1) continue;
            dfs_remain(v, u, 1 - pa_color);
        }
    }
    bool normal() {
        color.assign(n, -1);
        exception_table.assign(3, -1);
        dfs(0, 0, -1);
        k = *max_element(color.begin() + 1, color.end()) + 1;
        return true;
    }
    void dfs(int u, int pa, int pa_color) {
        color[u] = pa_color;
        if (u == pa) {
            // is root
            for (auto v : tree[u]) {
                dfs(v, u, 0);
            }
        } else if (tree[u].size() != 2) {
            for (auto v : tree[u]) {
                if (v == pa) continue;
                int child_color = (pa_color == 2? 0 : 1 - pa_color);
                dfs(v, u, child_color);
            }
        } else {
            int v = tree[u][0] + tree[u][1] - pa;
            if (exception_table[pa_color] != -1) {
                // case 1: follows previous exception
                dfs(v, u, exception_table[pa_color]);
            } else if (exception_table[0] == -1 && exception_table[1] == -1) {
                // case 2: first time in exception
                exception_table[pa_color] = 1 - pa_color;
                dfs(v, u, exception_table[pa_color]);
            } else {
                // case 3: I need new color
                exception_table[pa_color] = 2;
                exception_table[2] = 1 - pa_color;
                dfs(v, u, exception_table[pa_color]);
            }
        }
    }
    void print_color() {
        cout << k << endl;
        for (int i = 1; i < n; i++) {
            cout << color[i] + 1 << " ";
        }
        cout << endl;
    }
    int decide() {
        vector<int> see(k);
        int degree = 0;
        for (auto &x : see) {
            cin >> x;
            degree += x;
        }
        if (degree != 2) {
            for (int i = 0; i < k; i++) {
                if (see[i] == 1) {
                    return i + 1;
                }
            }
            return -1;
        } else {
            vector<int> e;
            for (int i = 0; i < k; i++) {
                if (see[i] != 0) e.emplace_back(i);
            }
            if (e[0] != -1 && exception_table[e[0]] == e[1]) {
                return e[0] + 1;
            } 
            if (e[1] != -1 && exception_table[e[1]] == e[0]) {
                return e[1] + 1;
            }
            return -1;
        }
    }
    void interaction() {
        int cmd;
        while (true) {
            cin >> cmd;
            if (cmd != 0) break;
            cout << decide() << endl;
        }
    }
};

int main() {
    int n; cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int pa; cin >> pa; pa--;
        tree[i].emplace_back(pa);
        tree[pa].emplace_back(i);
    }
    Solver solver(n, tree);
    solver.print_color();
    solver.interaction();
}

