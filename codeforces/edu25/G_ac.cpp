#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg1D {
    int n;
    vector<int> st, tag;
    Seg1D(int _n, const vector<int> &arr) : n(_n), st(4 * n, n), tag(4 * n, n) { build(0, n-1, 1, arr); }
    int query(int x) { return query(0, n-1, 1, x); }
    void modify(int L, int R, int val) { modify(0, n-1, 1, L, R, val); }
    void build(int l, int r, int idx, const vector<int> &arr) {
        if (l == r) {
            st[idx] = arr[l]; return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        st[idx] = min(st[lson], st[rson]);
    }
    void push(int idx, int lson, int rson) {
        if (tag[idx] != n) {
            st[lson] = min(tag[idx], st[lson]);
            st[rson] = min(tag[idx], st[rson]);
            tag[lson] = min(tag[idx], tag[lson]);
            tag[rson] = min(tag[idx], tag[rson]);
            tag[idx] = n;
        }
    }
    int query(int l, int r, int idx, int x) {
        if (l == x && r == x) {
            return st[idx];
        } else if (x < l || x > r) {
            return n;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        push(idx, lson, rson);
        return min(query(l, mid, lson, x), query(mid + 1, r, rson, x));
    }
    void modify(int l, int r, int idx, int L, int R, int val) {
        if (L <= l && r <= R) {
            st[idx] = min(tag[idx], val);
            tag[idx] = min(tag[idx], val);
            return;
        } else if (r < L || R < l) {
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        push(idx, lson, rson);
        modify(l, mid, lson, L, R, val);
        modify(mid+1, r, rson, L, R, val);
        st[idx] = min(st[lson], st[rson]);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<vector<int>> graph(n);
    for (int e = 0; e < n-1; e++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    int ts = -1;
    vector<int> root_path(n, n), in_tim(n, -1), out_tim(n, -1);
    function<void(int,int)> dfs = [&](int u, int pa) {
        in_tim[u] = ++ts;
        root_path[u] = min(root_path[u], u);
        for (auto v : graph[u]) {
            if (v == pa) continue;
            root_path[v] = min(root_path[v], root_path[u]);
            dfs(v, u);
        }
        out_tim[u] = ts;
    };
    // root
    int op, x, last = 0; cin >> op >> x;
    x = (x + last) % n;  // 0-based
    dfs(x, x);
    vector<int> seg_init(n);
    for (int u = 0; u < n; u++) {
        seg_init[in_tim[u]] = root_path[u];
    }
    Seg1D seg(n, seg_init);
    /*
    cerr << "debug: " << endl;
    cerr << "root = " << x+1 << endl;
    cerr << "in_tim = ";
    for (auto t : in_tim) cerr << t << " ";
    cerr << endl;
    cerr << "out_tim = ";
    for (auto t : out_tim) cerr << t << " ";
    cerr << endl;
    cerr << "root_path = ";
    for (auto t : root_path) cerr << t + 1 << " ";
    cerr << endl;
    */
    // start query
    for (int _q = 1; _q < q; _q++) {
        cin >> op >> x;
        x = (x + last) % n;  // 0-based
        if (op == 1) {
            // update: [0, in_tim-1], [out_tim+1, n-1]
            if (in_tim[x]-1 >= 0) seg.modify(0, in_tim[x]-1, root_path[x]);
            if (out_tim[x]+1 <= n-1) seg.modify(out_tim[x]+1, n-1, root_path[x]);
        } else {
            // query
            last = seg.query(in_tim[x]) + 1;
            cout << last << "\n";
        }
    }
}
