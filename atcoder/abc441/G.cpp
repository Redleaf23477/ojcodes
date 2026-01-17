#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL NEG_INF = -1'000'000'000ll * 200'000ll;

struct Seg1D {
    struct Node {
        LL mx;
        int face_up;
        int face_down;

        LL add;
        int flip;
    };

    size_t n;
    vector<Node> st;

    Seg1D(size_t _n) : n(_n), st(4 * n) {
        build(0, n - 1, 0);
    }

    void build(int l, int r, int idx) {
        if (r < l) {
            return;
        }
        if (l == r) {
            st[idx].mx = 0;
            st[idx].face_up = 1;
            st[idx].face_down = 0;
            st[idx].add = 0;
            st[idx].flip = 0;
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2 + 1, rson = idx * 2 + 2;
        build(l, mid, lson);
        build(mid + 1, r, rson);
        up(idx, lson, rson);
    }

    void down(int idx, int lson, int rson) {
        if (st[idx].flip) {
            st[lson].mx = st[lson].add = 0;
            st[rson].mx = st[rson].add = 0;
        }
        if (st[idx].flip % 2 == 1) {
            swap(st[lson].face_up, st[lson].face_down);
            swap(st[rson].face_up, st[rson].face_down);
        }

        if (st[lson].face_up > 0) {
            st[lson].mx += st[idx].add;
        }
        st[lson].add += st[idx].add;
        st[lson].flip += st[idx].flip;

        if (st[rson].face_up > 0) {
            st[rson].mx += st[idx].add;
        }
        st[rson].add += st[idx].add;
        st[rson].flip += st[idx].flip;

        st[idx].add = 0;
        st[idx].flip = 0;
    }
    void up(int idx, int lson, int rson) {
        st[idx].mx = max(st[lson].mx, st[rson].mx);
        st[idx].face_up = st[lson].face_up + st[rson].face_up;
        st[idx].face_down = st[lson].face_down + st[rson].face_down;
    }

    void flip(int l, int r, int idx, int L, int R) {
        if (r < L || R < l) {
            return;
        } 

        if (L <= l && r <= R) {
            st[idx].add = 0;
            st[idx].mx = 0;
            swap(st[idx].face_up, st[idx].face_down);
            st[idx].flip += 1;
            return;
        }

        int mid = (l + r) / 2, lson = idx * 2 + 1, rson = idx * 2 + 2;
        down(idx, lson, rson);
        flip(l, mid, lson, L, R);
        flip(mid + 1, r, rson, L, R);
        up(idx, lson, rson);
    }
    void flip(int L, int R) {
        flip(0, n - 1, 0, L, R);
    }

    void add(int l, int r, int idx, int L, int R, LL val) {
        if (r < L || R < l) {
            return;
        } 

        if (L <= l && r <= R) {
            st[idx].add += val;
            if (st[idx].face_up > 0) {
                st[idx].mx += val;
            }
            return;
        }

        int mid = (l + r) / 2, lson = idx * 2 + 1, rson = idx * 2 + 2;
        down(idx, lson, rson);
        add(l, mid, lson, L, R, val);
        add(mid + 1, r, rson, L, R, val);
        up(idx, lson, rson);
    }
    void add(int L, int R, LL val) {
        add(0, n - 1, 0, L, R, val);
    }

    LL query(int l, int r, int idx, int L, int R) {
        if (r < L || R < l) {
            return NEG_INF;
        }


        if (L <= l && r <= R) {
            return st[idx].mx;
        }

        int mid = (l + r) / 2, lson = idx * 2 + 1, rson = idx * 2 + 2;
        down(idx, lson, rson);
        return max(query(l, mid, lson, L, R), query(mid + 1, r, rson, L, R));
    }
    LL query(int L, int R) {
        return query(0, n - 1, 0, L, R);
    }
};

void solve() {
    size_t n, q; cin >> n >> q;

    Seg1D seg(n);
    while (q--) {
        size_t t, l, r; cin >> t >> l >> r; l--, r--;

        if (t == 1) {
            LL x; cin >> x;
            seg.add(l, r, x);
        } else if (t == 2) {
            seg.flip(l, r);
        } else {
            LL mx = seg.query(l, r);
            mx = max(mx, 0ll);
            cout << mx << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

