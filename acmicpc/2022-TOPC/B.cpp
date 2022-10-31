#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<LL,LL>;

struct Seg1D {
    static const LL NOTAG = 48763;
    int n;
    vector<LL> tag_add, tag_set;
    vector<LL> sum, sum_with_coef;
    Seg1D(int _n, vector<LL> const &arr) : n(_n), tag_add(4*n, 0), tag_set(4*n, NOTAG), sum(4*n), sum_with_coef(4*n) {
        build(0, n-1, 1, arr);
    }
    void up(int idx, int lson, int rson) {
        sum[idx] = sum[lson] + sum[rson];
        sum_with_coef[idx] = sum_with_coef[lson] + sum_with_coef[rson];
    }
    void update_add(int idx, LL l, LL r, LL val) {
        tag_add[idx] += val;
        sum[idx] += (r - l + 1) * val;
        sum_with_coef[idx] += (l + r + 2) * (r - l + 1) / 2 * val;
    }
    void update_set(int idx, LL l, LL r, LL val) {
        tag_add[idx] = 0;
        tag_set[idx] = val;
        sum[idx] = (r - l + 1) * val;
        sum_with_coef[idx] = (l + r + 2) * (r - l + 1) / 2 * val;
    }
    void down(int idx, int lson, int rson, int l, int mid, int r) {
        if (tag_set[idx] != NOTAG) {
            update_set(lson, l, mid, tag_set[idx]);
            update_set(rson, mid+1, r, tag_set[idx]);
            tag_set[idx] = NOTAG;
        }
        if (tag_add[idx] != 0) {
            update_add(lson, l, mid, tag_add[idx]);
            update_add(rson, mid+1, r, tag_add[idx]);
            tag_add[idx] = 0;
        }
    }
    void build(int l, int r, int idx, vector<LL> const &arr) {
        if (l == r) {
            sum[idx] = arr[l];
            sum_with_coef[idx] = (l + 1) * arr[l];
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        up(idx, lson, rson);
    }
    void add(int l, int r, int idx, int L, int R, LL val) {
        if (L <= l && r <= R) { 
            update_add(idx, l, r, val); return;
        } 
        if (r < L || R < l) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(idx, lson, rson, l, mid, r);
        add(l, mid, lson, L, R, val);
        add(mid+1, r, rson, L, R, val);
        up(idx, lson, rson);
    }
    void set(int l, int r, int idx, int L, int R, LL val) {
        if (L <= l && r <= R) {
            update_set(idx, l, r, val); return;
        }
        if (r < L || R < l) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(idx, lson, rson, l, mid, r);
        set(l, mid, lson, L, R, val);
        set(mid+1, r, rson, L, R, val);
        up(idx, lson, rson);
    }
    T query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            LL c = sum_with_coef[idx] - sum[idx] * (l - L);
            LL s = sum[idx];
            return T(c, s);
        }
        if (r < L || R < l) return T(0, 0);
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(idx, lson, rson, l, mid, r);
        auto [lc, ls] = query(l, mid, lson, L, R);
        auto [rc, rs] = query(mid+1, r, rson, L, R);
        return T(lc + rc, ls + rs);
    }
    void add(int L, int R, int val) { add(0, n-1, 1, L, R, val); }
    void set(int L, int R, int val) { set(0, n-1, 1, L, R, val); }
    bool query(int L, int R) { 
        auto [coef, sum] = query(0, n-1, 1, L, R);
        if (sum == 0) return coef == 0;
        else return coef % sum == 0;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    Seg1D st(n, arr);
    while (q--) {
        int op; cin >> op;
        int l, r, x;
        if (op == 1) {
            cin >> l >> r >> x; l--, r--;
            st.add(l, r, x);
        } else if (op == 2) {
            cin >> l >> r >> x; l--, r--;
            st.set(l, r, x);
        } else {
            cin >> l >> r; l--, r--;
            cout << (st.query(l, r)? "Yes\n" : "No\n");
        }
    }
}

