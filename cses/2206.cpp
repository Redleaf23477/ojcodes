#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr int INF = 2e9;

struct Seg1D {
    int n;
    int default_sign;
    vector<int> st;

    void build(int l, int r, int idx, const vector<int> &arr) {
        if (l == r) {
            st[idx] = arr[l] + default_sign * l; return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        st[idx] = min(st[lson], st[rson]);
    }

    void modify(int l, int r, int idx, int x, int val) {
        if (l == x && r == x) {
            st[idx] = val + default_sign * l; return;
        } else if (x < l || r < x) {
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, x, val);
        modify(mid+1, r, rson, x, val);
        st[idx] = min(st[lson], st[rson]);
    }

    int query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) return st[idx]; 
        else if (r < L || R < l) return INF;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        return min(query(l, mid, lson, L, R), query(mid+1, r, rson, L, R));
    }

    void modify(int x, int val) { return modify(0, n-1, 1, x, val); }
    int query(int L, int R) { return query(0, n-1, 1, L, R); }

    Seg1D(int _n, int sgn, const vector<int> &arr) : n(_n), default_sign(sgn), st(4*n) {
        build(0, n-1, 1, arr);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    Seg1D pos(n, 1, arr), neg(n, -1, arr);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x, v; cin >> x >> v;
            neg.modify(x-1, v);
            pos.modify(x-1, v);
        } else {
            int k; cin >> k; k--;
            int ans = INF;
            if (k >= 0) {
                ans = min(ans, neg.query(0, k) + k);
            }
            if (k < n) {
                ans = min(ans, pos.query(k, n-1) - k);
            }
            cout << ans << "\n";
        }
    }
}

