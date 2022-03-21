#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg1D {
    int n;
    using Node = tuple<LL,LL,LL>;  // (sum, tag_set, tag_add), 0 := no tag
    vector<Node> st;

    void up(Node &rt, Node &lchild, Node &rchild) {
        auto &[l_sum, l_set, l_add] = lchild;
        auto &[r_sum, r_set, r_add] = rchild;
        rt = Node(l_sum + r_sum, 0, 0);
    }

    void down(Node &rt, Node &lchild, Node &rchild, int l_len, int r_len) {
        auto &[o_sum, o_set, o_add] = rt;
        auto &[l_sum, l_set, l_add] = lchild;
        auto &[r_sum, r_set, r_add] = rchild;

        if (o_set != 0) {
            l_sum = o_set * l_len, l_set = o_set, l_add = 0;
            r_sum = o_set * r_len, r_set = o_set, r_add = 0;
        }
        if (o_add != 0) {
            l_sum += o_add * l_len, l_add += o_add;
            r_sum += o_add * r_len, r_add += o_add;
        }
        o_set = o_add = 0;
    }

    void build(int l, int r, int idx, const vector<LL> &arr) {
        if (l == r) {
            st[idx] = Node(arr[l], 0, 0); return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        up(st[idx], st[lson], st[rson]);
    }

    void set_val(int l, int r, int idx, int L, int R, LL val) {
        if (L <= l && r <= R) {
            st[idx] = Node(val * (r - l + 1), val, 0); return;
        } else if (r < L || R < l) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(st[idx], st[lson], st[rson], mid - l + 1, r - mid);
        set_val(l, mid, lson, L, R, val);
        set_val(mid+1, r, rson, L, R, val);
        up(st[idx], st[lson], st[rson]);
    }

    void set_val(int L, int R, LL val) { set_val(0, n-1, 1, L, R, val); }

    void add_val(int l, int r, int idx, int L, int R, LL val) {
        if (L <= l && r <= R) {
            auto &[sum, tag_set, tag_add] = st[idx];
            sum += (r - l + 1) * val, tag_add += val;
            return;
        } else if (r < L || R < l) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(st[idx], st[lson], st[rson], mid - l + 1, r - mid);
        add_val(l, mid, lson, L, R, val);
        add_val(mid+1, r, rson, L, R, val);
        up(st[idx], st[lson], st[rson]);
    }

    void add_val(int L, int R, LL val) { add_val(0, n-1, 1, L, R, val); }

    LL query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            return get<0>(st[idx]);
        } else if (r < L || R < l) return 0;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(st[idx], st[lson], st[rson], mid - l + 1, r - mid);
        return query(l, mid, lson, L, R) + query(mid + 1, r, rson, L, R);
    }

    LL query(int L, int R) { return query(0, n-1, 1, L, R); }

    Seg1D(int _n, const vector<LL> &arr) : n(_n), st(4*n) {
        build(0, n-1, 1, arr);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    Seg1D st(n, arr);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, val; cin >> l >> r >> val;
            st.add_val(l-1, r-1, val);
        } else if (op == 2) {
            int l, r, val; cin >> l >> r >> val;
            st.set_val(l-1, r-1, val);
        } else {
            int l, r; cin >> l >> r;
            cout << st.query(l-1, r-1) << "\n";
        }
    }
}

