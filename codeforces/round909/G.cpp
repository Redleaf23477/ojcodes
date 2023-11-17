#include <bits/stdc++.h>
using namespace std;
using LL = long long;

using Query = tuple<int,int,int>;

struct Seg1D {
    using Node = pair<int,int>; // (val, source)
    int n;
    vector<Node> st;
    Seg1D(int _n) : n(_n), st(4 * n, Node(-1, -1)) {}

    void modify(int pos, int val) { modify(0, n - 1, 1, pos, val); }
    void modify(int l, int r, int idx, int pos, int val) {
        if (pos < l || r < pos) return;
        if (l == pos && pos == r) {
            st[idx] = Node(val, pos);  
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, pos, val);
        modify(mid + 1, r, rson, pos, val);
        if (st[lson].first > st[rson].first) {
            st[idx] = st[lson];
        } else {
            st[idx] = st[rson];
        }
    }

    Node query(int pos) { return query(0, n - 1, 1, 0, pos); }
    Node query(int l, int r, int idx, int L, int R) {
        if (r < L || R < l) return Node(-1, -1);
        if (L <= l && r <= R) return st[idx];
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        Node lhs = query(l, mid, lson, L, R);
        Node rhs = query(mid + 1, r, rson, L, R);
        if (lhs.first > rhs.first) return lhs;
        else return rhs;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }
    vector<int> perm(n), pos_in_perm(n);
    for (int i = 0; i < n; i++) {
        cin >> perm[i]; perm[i]--;
        pos_in_perm[perm[i]] = i;
    }
    vector<bool> ans(q, false), gg(q, false);
    vector<vector<Query>> qry(n);
    for (int i = 0; i < q; i++) {
        int l, r, x; cin >> l >> r >> x; l--, r--, x--;
        qry[x].emplace_back(l, r, i);
    }
    Seg1D seg(n);
    vector<priority_queue<pair<int,int>>> query_buffer(n);
    function<void(int,int)> dfs = [&](int u, int pa) {
        // cerr << "dfs(" << u << ")" << endl;
        // add my query
        for (auto [l, r, qid] : qry[u]) {
            auto &qb = query_buffer[l];
            qb.emplace(r, qid);
            if (qb.top().second == qid) {
                // cerr << "push query (l = " << l << ", r = " << r << ")" << endl;
                seg.modify(l, r);
            }
        }
        // solve with me
        int my_pos = pos_in_perm[u];
        while (true) {
            auto [max_r, source_l] = seg.query(my_pos);
            // cerr << u << ": seg gives (max_r = " << max_r << ", source_l = " << source_l << ")" << endl;
            if (my_pos > max_r) break;
            // I solve a query in query_buffer[source_l]
            auto &qb = query_buffer[source_l];
            auto [__, qid] = qb.top(); qb.pop();
            ans[qid] = true;
            // cerr << "query[" << qid << "] = true" << endl;
            if (!qb.empty()) {
                // cerr << "push query (l = " << source_l << ", r = " << qb.top().first << ")" << endl;
                seg.modify(source_l, qb.top().first);
            } else {
                // cerr << "push query (l = " << source_l << ", r = " << -1 << ")" << endl;
                seg.modify(source_l, -1);
            }
        }
        // dfs
        for (auto v : tree[u]) {
            if (pa == v) continue;
            dfs(v, u);
        }
        // remove my query
        for (auto [l, r, qid] : qry[u]) {
            if (!ans[qid]) gg[qid] = true;
        }

    };
    dfs(0, 0);
    for (int i = 0; i < q; i++) {
        if (gg[i]) cout << "NO\n";
        else if (ans[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

