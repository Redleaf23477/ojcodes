#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg1D {
    using Node = tuple<LL,LL,LL,LL>;  // (sum, mx_pre, mx_suf, arr)
    int n;
    vector<Node> st;

    void up(Node &rt, Node &lchild, Node &rchild) {
        const auto &[l_sum, l_pre, l_suf, l_arr] = lchild;
        const auto &[r_sum, r_pre, r_suf, r_arr] = rchild;
        rt = Node(l_sum + r_sum, 
                max({0ll, l_pre, l_sum + r_pre}),
                max({0ll, r_suf, r_sum + l_suf}),
                max({0ll, l_arr, r_arr, l_suf + r_pre}));
    }

    void build(int l, int r, int idx, const vector<LL> &arr) {
        if (l == r) {
            LL mx = max(0ll, arr[l]);
            st[idx] = Node(arr[l], mx, mx, mx);
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        up(st[idx], st[lson], st[rson]);
    }

    void modify(int l, int r, int idx, int x, LL val) {
        if (l == x && x == r) {
            LL mx = max(0ll, val);
            st[idx] = Node(val, mx, mx, mx);
            return;
        } if (x < l || r < x) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, x, val);
        modify(mid+1, r, rson, x, val);
        up(st[idx], st[lson], st[rson]);
    }

    void modify(int x, LL val) { modify(0, n-1, 1, x, val); }
    LL query() { return get<3>(st[1]); }

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
        int x, val; cin >> x >> val;
        st.modify(x-1, val);
        cout << st.query() << "\n";
    }
}

