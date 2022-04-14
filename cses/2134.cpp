#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

struct Seg1D {
    int n;
    vector<int> st;
    Seg1D(int _n): n(_n), st(4*n) {}
    void modify(int l, int r, int idx, int x, int val) {
        if (l == x && r == x) { st[idx] = val; return; }
        if (x < l || r < x) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, x, val);
        modify(mid+1, r, rson, x, val);
        st[idx] = max(st[lson], st[rson]);
    }
    void modify(int x, int val) { modify(0, n-1, 1, x, val); }
    int query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) return st[idx];
        if (r < L || R < l) return 0;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        return max(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
    }
    int query(int L, int R) { return query(0, n-1, 1, L, R); }
};

struct TreeHLD {
    // internal data structures
    struct ListInfo {
        int offset;         // start index in the flat_list
        int parent;         // parent list index
        int branch_offset;  // parent vertex index in parent list
        int length;         // length of list
        ListInfo(int beg, int pa, int branch): offset(beg), parent(pa), branch_offset(branch), length(0) {}
    };
    struct NodeInfo {
        int list_index;     // which list
        int offset;         // index in list
    };
    // original list
    int n;
    vector<vector<int>> graph;
    vector<int> tree_size;
    // heavy light decomposition
    vector<ListInfo> lists;
    vector<NodeInfo> nodes;
    vector<int> flat_list;  // concate all lists into one
    // problem solving
    Seg1D st;

    TreeHLD(int _n): n(_n), graph(n), tree_size(n, 0), nodes(n), st(n) {}
    void add_edge(int u, int v) {
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    // calculate tree size
    void dfs1(int u, int pa) {
        tree_size[u] = 1;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            dfs1(v, u);
            tree_size[u] += tree_size[v];
        }
    }
    // decomposition
    void dfs2(int u, int pa, int list_index) {
        // update info of u and link
        lists[list_index].length += 1;
        nodes[u].list_index = list_index;
        nodes[u].offset = lists[list_index].length - 1;
        flat_list.emplace_back(u);
        // find largest subtree
        int max_tree = -1;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            if (max_tree == -1 || tree_size[v] > tree_size[max_tree]) max_tree = v;
        }
        // hit leaf, return
        if (max_tree == -1) return;
        // heavy part
        dfs2(max_tree, u, list_index);
        // light parts
        for (auto v : graph[u]) {
            if (v == max_tree || v == pa) continue;
            lists.emplace_back(flat_list.size(), list_index, nodes[u].offset);
            dfs2(v, u, lists.size() - 1);
        }
    }
    void run_hld() {
        dfs1(0, 0);
        lists.emplace_back(0, -1, -1);
        dfs2(0, 0, 0);
    }
    // segtree interface
    void st_modify(int x, int v) { st.modify(x, v); }
    int st_query(int L, int R) { return st.query(L, R); }
    // find lca
    int find_lca(int u, int v) {
        // jump list until on same list
        while (nodes[u].list_index != nodes[v].list_index) {
            if (nodes[u].list_index > nodes[v].list_index) swap(u, v);
            auto &v_list = lists[nodes[v].list_index];
            auto &v_pa_list = lists[v_list.parent];
            v = flat_list[v_pa_list.offset + v_list.branch_offset];
        }
        // u, v on the same list, return the higher one
        return (nodes[u].offset < nodes[v].offset? u : v);
    }
    // problem solving
    int lca_max_query(int u, int v) {
        int ans = 0;
        // jump list until on same list
        while (nodes[u].list_index != nodes[v].list_index) {
            if (nodes[u].list_index > nodes[v].list_index) swap(u, v);
            auto &v_list = lists[nodes[v].list_index];
            auto &v_pa_list = lists[v_list.parent];
            ans = max(ans, st.query(v_list.offset, v_list.offset + nodes[v].offset));
            v = flat_list[v_pa_list.offset + v_list.branch_offset];
        }
        // u, v on the same list, return the higher one
        auto &uv_list = lists[nodes[u].list_index];
        if (nodes[u].offset > nodes[v].offset) swap(u, v);
        ans = max(ans, st.query(uv_list.offset + nodes[u].offset, uv_list.offset + nodes[v].offset));
        return ans;
    }

    // return label (index in flat_list)
    int get_label(int u) {
        int li = nodes[u].list_index;
        return lists[li].offset + nodes[u].offset;
    }
};



int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> arr(n); 
    for (auto &x : arr) cin >> x;
    TreeHLD tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; 
        tree.add_edge(u-1, v-1);
    }
    tree.run_hld();

    for (int i = 0; i < n; i++) {
        tree.st_modify(tree.get_label(i), arr[i]);
    }
    
    while (q--) {
        int op, a, b; cin >> op >> a >> b;
        if (op == 1) {
            tree.st_modify(tree.get_label(a-1), b);
        } else {
            cout << tree.lca_max_query(a-1, b-1) << " ";
        }
    }
    cout << "\n";
}