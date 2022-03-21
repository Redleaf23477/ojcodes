#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg1D {
    int n;
    using Node = tuple<LL,LL,LL>;  // (sum, tag_add, tag_cnt)
    vector<Node> st;

    LL base_sum(LL l, LL r) {
        // (n-l) + ... + (n-r)
        return -(n + n - l - r) * (r - l + 1) / 2;
    }

    void up(Node &rt, Node &lchild, Node &rchild) {
        auto &[l_sum, l_add, l_cnt] = lchild;
        auto &[r_sum, r_add, r_cnt] = rchild;
        rt = Node(l_sum + r_sum, 0, 0);
    }

    void down(Node &rt, Node &lchild, Node &rchild, int l, int mid, int r) {
        auto &[o_sum, o_add, o_cnt] = rt;
        auto &[l_sum, l_add, l_cnt] = lchild;
        auto &[r_sum, r_add, r_cnt] = rchild;
        int l_len = mid - l + 1, r_len = r - mid;
        if (o_cnt != 0) {
            l_sum += l_len * o_add + base_sum(l, mid) * o_cnt, l_add += o_add, l_cnt += o_cnt;
            r_sum += r_len * o_add + base_sum(mid+1, r) * o_cnt, r_add += o_add, r_cnt += o_cnt;
        }
        o_add = o_cnt = 0;
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

    void modify(int l, int r, int idx, int L, int R, LL val) {
        if (L <= l && r <= R) {
            auto &[sum, tag_add, tag_cnt] = st[idx];
            sum += (r - l + 1) * val + base_sum(l, r) * 1;
            tag_add += val;
            tag_cnt += 1;
            return;
        } else if (r < L || R < l) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(st[idx], st[lson], st[rson], l, mid, r);
        modify(l, mid, lson, L, R, val);
        modify(mid+1, r, rson, L, R, val);
        up(st[idx], st[lson], st[rson]);
    }

    LL query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) return get<0>(st[idx]); 
        else if (r < L || R < l) return 0;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(st[idx], st[lson], st[rson], l, mid, r); 
        return query(l, mid, lson, L, R) + query(mid + 1, r, rson, L, R);
    }

    void modify(int L, int R, LL val) { modify(0, n-1, 1, L, R, val); }
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
        int op, l, r; cin >> op >> l >> r; l--, r--;
        if (op == 2) {
            LL ans = st.query(l, r);
            cout << ans << "\n";
        } else {
            st.modify(l, r, n - l + 1);
        }
    }
}

