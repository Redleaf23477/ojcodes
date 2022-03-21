#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg1D {
    int n;
    vector<int> st, data;

    void up(int idx, int lson, int rson) {
        st[idx] = (data[st[lson]] > data[st[rson]]? st[lson] : st[rson]);
    }

    void build(int l, int r, int idx) {
        if (l == r) { 
            st[idx] = l; return;
        } 
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson);
        build(mid+1, r, rson);
        up(idx, lson, rson);
    }

    void modify(int l, int r, int idx, int x, int delta) {
        if (l == x && x == r) {
            data[l] -= delta; return;
        } else if (x < l || r < x) {
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, x, delta);
        modify(mid+1, r, rson, x, delta);
        up(idx, lson, rson);
    }

    int query(int l, int r, int idx, int val) {
        if (data[st[idx]] < val) {
            return -1;
        } else if (l == r) {
            return st[idx];
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        if (data[st[lson]] >= val) {
            return query(l, mid, lson, val);
        } else {
            return query(mid+1, r, rson, val);
        }
    }

    void modify(int x, int delta) { modify(0, n-1, 1, x, delta); }
    int query(int val) { return query(0, n-1, 1, val); }

    Seg1D(int _n, const vector<int> &arr) : n(_n), st(4*n), data(arr) {
        build(0, n-1, 1);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    Seg1D st(n, arr);
    while (q--) {
        int x; cin >> x;
        int ans = st.query(x);
        st.modify(ans, x);
        cout << ans + 1 << " ";
    }
    cout << "\n";
}

