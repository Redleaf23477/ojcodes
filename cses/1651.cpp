#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg1D {
    int n;
    vector<LL> st, tag;

    void down(int idx, int lson, int rson, int len) {
        st[idx] += len * tag[idx];
        tag[lson] += tag[idx];
        tag[rson] += tag[idx];
        tag[idx] = 0;
    }

    void up(int idx, int lson, int rson, int l_len, int r_len) {
        st[idx] = st[lson] + tag[lson] * l_len + st[rson] + tag[rson] * r_len;
    }

    void build(int l, int r, int idx, const vector<LL> &arr) {
        if (l == r) {
            st[idx] = arr[l]; return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        up(idx, lson, rson, mid - l + 1, r - mid);
    }

    void modify(int l, int r, int idx, int L, int R, int val) {
        if (L <= l && r <= R) {
            tag[idx] += val; return;
        } else if (r < L || R < l) {
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(idx, lson, rson, r - l + 1);
        modify(l, mid, lson, L, R, val);
        modify(mid + 1, r, rson, L, R, val);
        up(idx, lson, rson, mid - l + 1, r - mid);
    }

    LL query(int l, int r, int idx, int x) {
        if (l == x && r == x) {
            return st[idx] + tag[idx];
        } else if (x < l || r < x) {
            return 0;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(idx, lson, rson, r - l + 1);
        return query(l, mid, lson, x) + query(mid+1, r, rson, x);
    }

    void modify(int L, int R, int val) { modify(0, n-1, 1, L, R, val); }
    LL query(int x) { return query(0, n-1, 1, x); }

    Seg1D(int _n, const vector<LL> &arr) : n(_n), st(4*n), tag(4*n, 0) {
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
            int a, b, v; cin >> a >> b >> v;
            st.modify(a - 1, b - 1, v);
        } else {
            int x; cin >> x;
            cout << st.query(x-1) << "\n";
        }
    }
}

