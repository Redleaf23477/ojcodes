#include <bits/stdc++.h>
using namespace std;

struct VirtualTree {
    size_t N;
    vector<vector<size_t>> &tree;
    vector<size_t> &A;
    VirtualTree(size_t n, vector<vector<size_t>> &t, vector<size_t> &a)
        : N(n), tree(t), A(a) {}

    size_t target;
    void build(size_t t) {
        vt_nodes.clear();
        target = t;

        is_leaf.assign(N, true);
        dfs_pre(0, 0);

        dfs(0, 0);
    }

    vector<bool> is_leaf;
    bool dfs_pre(size_t u, size_t pa) {
        if (A[u] != target) is_leaf[u] = false;

        bool has_leaf = false;
        for (auto v : tree[u]) {
            if (v == pa) continue;
            has_leaf |= dfs_pre(v, u);
            if (has_leaf) is_leaf[u] = false;
        }

        return has_leaf || is_leaf[u];
    }

    vector<size_t> vt_nodes;
    struct stk_node { size_t index; int value; };
    vector<stk_node> stk;
    void dfs(size_t u, size_t pa) {
        stk.emplace_back((stk_node){u, 0});
        if (is_leaf[u]) {
            for (size_t i = 0; i < stk.size(); i++) {
                stk[i].value += 1;
            }
            for (size_t i = 0; i + 1 < stk.size(); i++) {
                if (stk[i].value > stk[i + 1].value) {
                    vt_nodes.emplace_back(stk[i].index);
                }
            }
            cerr << "dfs to leaf " << u + 1 << ", stk=";
            for (auto [idx, val] : stk) cerr << "(" << idx + 1 << ", " << val << ")";
            cerr << endl;
        }
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dfs(v, u);
        }
        stk.pop_back();
    }

    void print() {
        cout << "VT_leaf(" << target + 1 << "): ";
        for (size_t i = 0; i < N; i++) {
            if (is_leaf[i]) cout << i + 1 << " ";
        }
        cout << "\n";

        cout << "VT(" << target + 1 << "): ";
        for (auto x : vt_nodes) {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
};

int main() {
    size_t N; cin >> N;
    vector<vector<size_t>> tree(N);
    for (size_t i = 1; i < N; i++) {
        size_t u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    vector<size_t> A(N);
    for (auto &x : A) {
        cin >> x; x--;
    }

    VirtualTree vt(N, tree, A);
    for (size_t a = 0; a < N; a++) {
        vt.build(a);
        vt.print();
    }
}
