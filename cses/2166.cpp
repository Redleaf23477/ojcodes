#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL INF = 1e18;

struct Seg1D {
    using Node = tuple<LL,LL>;  // (seg_sum, max_seg_prefix)
    int n;
    vector<Node> st;

    void up(Node &rt, Node &lchild, Node &rchild) {
        auto &[l_sum, l_pre] = lchild;
        auto &[r_sum, r_pre] = rchild;
        rt = Node(l_sum + r_sum, max({0ll, l_pre, l_sum + r_pre}));
    }

    void build(int l, int r, int idx, const vector<LL> &arr) {
        if (l == r) {
            st[idx] = Node(arr[l], max(0ll, arr[l]));
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson, arr);
        build(mid + 1, r, rson, arr);
        up(st[idx], st[lson], st[rson]);
    }

    void modify(int l, int r, int idx, int x, LL v) {
        if (l == x && r == x) {
            st[idx] = Node(v, max(0ll, v));
            return;
        } else if (x < l || r < x) {
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, x, v);
        modify(mid+1, r, rson, x, v);
        up(st[idx], st[lson], st[rson]);
    }

    Node query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            return st[idx];
        } else if (r < L || R < l) {
            return Node(0, -INF);
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        Node ans;
        Node l_ans = query(l, mid, lson, L, R);
        Node r_ans = query(mid+1, r, rson, L, R);
        up(ans, l_ans, r_ans);
        return ans;
    }

    void modify(int x, LL v) { modify(0, n-1, 1, x, v); }
    LL query(int L, int R) { 
        auto [range_sum, ans] = query(0, n-1, 1, L, R);
        return ans;
    }

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
        int op, a, b; cin >> op >> a >> b;
        if (op == 1) {
            st.modify(a-1, b);
        } else {
            cout << st.query(a-1, b-1) << "\n";
        }
    }
}

