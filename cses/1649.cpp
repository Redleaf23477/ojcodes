#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr int INF = 1e9;

struct Seg1D {
    int n; 
    vector<int> st;

    void init(int l, int r, int idx, const vector<int> &arr) {
        if (l == r) {
            st[idx] = arr[l]; return;
        }
        int mid = (l + r)/2, lson = idx * 2 , rson = idx * 2 + 1;
        init(l, mid, lson, arr);
        init(mid + 1, r, rson, arr);
        st[idx] = min(st[lson], st[rson]);
    }
    void modify(int l, int r, int idx, int x, int v) {
        if (l == x && r == x) {
            st[idx] = v; return;
        } else if (x < l || r < x) {
            return;
        }
        int mid = (l + r)/2, lson = idx * 2 , rson = idx * 2 + 1;
        modify(l, mid, lson, x, v);
        modify(mid+1, r, rson, x, v);
        st[idx] = min(st[lson], st[rson]);
    }
    void modify(int x, int v) { modify(0, n-1, 1, x, v); }
    int query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            return st[idx];
        } else if (r < L || R < l) {
            return INF; 
        }
        int mid = (l + r)/2, lson = idx * 2 , rson = idx * 2 + 1;
        return min(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
    }
    int query(int L, int R) { return query(0, n-1, 1, L, R); }

    Seg1D(int _n, const vector<int> &arr) : n(_n), st(4*n) {
        init(0, n-1, 1, arr);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    vector<int> arr(n);
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

