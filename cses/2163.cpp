#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg1D {
    int n;
    vector<int> st;

    void build(int l, int r, int idx) {
        if (l == r) { 
            st[idx] = 1; return;
        } 
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson);
        build(mid+1, r, rson);
        st[idx] = st[lson] + st[rson];
    }

    void modify(int l, int r, int idx, int x, int val) {
        if (l == x && x == r) {
            st[idx] = val; return;
        } else if (x < l || r < x) {
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, x, val);
        modify(mid+1, r, rson, x, val);
        st[idx] = st[lson] + st[rson];
    }

    int query(int l, int r, int idx, int val) {
        if (st[idx] < val) {
            return -1;
        } else if (l == r) {
            return l;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        if (val <= st[lson]) {
            return query(l, mid, lson, val);
        } else {
            return query(mid+1, r, rson, val - st[lson]);
        }
    }

    void modify(int x, int val) { modify(0, n-1, 1, x, val); }
    int query(int val) { return query(0, n-1, 1, val); }

    Seg1D(int _n) : n(_n), st(4*n) {
        build(0, n-1, 1);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, K; cin >> n >> K;
    Seg1D st(n); 
    for (int i = 0, acc = 1, left = n; i < n; i++, left -= 1) {
        int k = K % left;
        acc = (acc + k > left? acc + k - left : acc + k);
        int idx = st.query(acc);
        cout << idx + 1 << " ";
        st.modify(idx, 0);
    }
    cout << "\n";
}

