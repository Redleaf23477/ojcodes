#include <bits/stdc++.h>
using namespace std;

/*
struct Seg1D {
    int n;
    vector<int> st;

    void modify(int l, int r, int idx, int x, int val) {
        if (l == x && r == x) {
            st[idx] += val; return;
        } else if (x < l || r < x) {
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, x, val);
        modify(mid+1, r, rson, x, val);
        st[idx] = st[lson] + st[rson];
    }
    int query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            return st[idx];
        } else if (r < L || R < l) {
            return 0;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        return query(l, mid, lson, L, R) + query(mid+1, r, rson, L, R);
    }

    void modify(int x, int val) { return modify(0, n-1, 1, x, val); }
    int query(int L, int R) { return query(0, n-1, 1, L, R); }

    Seg1D(int _n) : n(_n), st(4*n, 0) {}
};
*/

struct BIT {
    int n; 
    vector<int> bit;
    int lowbit(int x) { return x & -x; }
    void modify(int x, int v) {
        for (; x <= n; x += lowbit(x)) bit[x] += v;
    }
    int query(int x) {
        int ans = 0;
        for (; x > 0; x -= lowbit(x)) ans += bit[x];
        return ans;
    }
    BIT(int _n) : n(_n), bit(n+1, 0) {}
};

void sort_uniq(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    auto it = unique(arr.begin(), arr.end());
    arr.erase(it, arr.end());
}

int val_mp(int x, const vector<int> &arr) {
    return lower_bound(arr.begin(), arr.end(), x) - arr.begin() + 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    // input & relabel
    int n, m; cin >> n >> m;
    vector<int> val; val.reserve(3*n);
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    val.insert(val.end(), arr.begin(), arr.end());
    vector<tuple<char,int,int>> qry(m); 
    for (auto &[op, a, b] : qry) {
        cin >> op >> a >> b;
        if (op == '?') val.emplace_back(a), val.emplace_back(b);
        else a--, val.emplace_back(b);
    }
    sort_uniq(val);
    for (auto &x : arr) x = val_mp(x, val);
    for (auto &[op, a, b] : qry) {
        if (op == '?') a = val_mp(a, val), b = val_mp(b, val);
        else b = val_mp(b, val);
    }
    // solve
    BIT st(val.size() + 1);
    for (auto x : arr) {
        st.modify(x, 1);
    }
    for (const auto &[op, a, b] : qry) {
        if (op == '?') {
            cout << st.query(b) - st.query(a-1) << "\n";
        } else {
            st.modify(arr[a], -1);
            arr[a] = b;
            st.modify(arr[a], 1);
        }
    }
}

