#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg1D {
    struct Node {
        LL data;
        shared_ptr<Node> lchild, rchild;
        Node () : data(0), lchild(nullptr), rchild (nullptr) {}
        Node (LL d, shared_ptr<Node> l, shared_ptr<Node> r) : data(d), lchild(l), rchild (r) {}
    };
    using NodePtr = shared_ptr<Node>;

    int n;
    vector<NodePtr> st;

    void build(int l, int r, NodePtr &rt, const vector<LL> &arr) {
        if (l == r) {
            rt->data = arr[l]; return;
        }
        int mid = (l + r) / 2;
        if (l <= mid) {
            rt->lchild = make_shared<Node>();
            build(l, mid, rt->lchild, arr);
            rt->data += rt->lchild->data;
        }
        if (mid+1 <= r) {
            rt->rchild = make_shared<Node>();
            build(mid+1, r, rt->rchild, arr);
            rt->data += rt->rchild->data;
        }
    }

    void modify(int l, int r, NodePtr &rt, int pos, LL val) {
        if (l == pos && r == pos) {
            rt->data = val; return;
        }
        int mid = (l + r) / 2;
        rt->data = 0;

        if (l <= pos && pos <= mid) {
            NodePtr new_child = make_shared<Node>(0, rt->lchild->lchild, rt->lchild->rchild);
            rt->lchild = new_child;
            modify(l, mid, rt->lchild, pos, val);
        } else {
            NodePtr new_child = make_shared<Node>(0, rt->rchild->lchild, rt->rchild->rchild);
            rt->rchild = new_child;
            modify(mid+1, r, rt->rchild, pos, val);
        }

        if (rt->lchild) rt->data += rt->lchild->data;
        if (rt->rchild) rt->data += rt->rchild->data;
    }

    void modify(int k, int pos, LL val) { modify(0, n-1, st[k], pos, val); }

    LL query(int l, int r, NodePtr &rt, int L, int R) {
        if (L <= l && r <= R) return rt->data;
        else if (r < L || R < l) return 0;
        int mid = (l + r) / 2;
        LL ans = 0;
        if (rt->lchild) ans += query(l, mid, rt->lchild, L, R);
        if (rt->rchild) ans += query(mid+1, r, rt->rchild, L, R);
        return ans;
    }

    LL query(int k, int L, int R) { return query(0, n-1, st[k], L, R); }

    void duplicate(int k) {
        st.emplace_back(make_shared<Node>(st[k]->data, st[k]->lchild, st[k]->rchild));
    }

    Seg1D(int _n, const vector<LL> &arr) : n(_n) {
        st.emplace_back(make_shared<Node>());
        build(0, n-1, st.front(), arr);
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
            int k, val, pos; cin >> k >> pos >> val;
            st.modify(k - 1, pos - 1, val);
        } else if (op == 2) {
            int k, l, r; cin >> k >> l >> r;
            cout << st.query(k - 1, l - 1, r - 1) << "\n";
        } else {
            int k; cin >> k;
            st.duplicate(k - 1);
        }
    }
}

