#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<int,int>;

struct Seg1D {
    int n; 
    vector<int> st_min, st_max;
    Seg1D(int _n) : n(_n), st_min(4*n), st_max(4*n) { build(0, n-1, 1); }
    void build(int l, int r, int idx) {
        if (l == r) {
            st_min[idx] = st_max[idx] = l; return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson);
        build(mid+1, r, rson);
        st_min[idx] = min(st_min[lson], st_min[rson]);
        st_max[idx] = max(st_max[lson], st_max[rson]);
    }
    void modify(int l, int r, int idx, int pos, int val) {
        if (l == r && l == pos) {
            st_min[idx] = min(st_min[idx], val);
            st_max[idx] = max(st_max[idx], val);
            return;
        } 
        if (pos < l || r < pos) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, pos, val);
        modify(mid+1, r, rson, pos, val);
        st_min[idx] = min(st_min[lson], st_min[rson]);
        st_max[idx] = max(st_max[lson], st_max[rson]);
    }
    T query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            return T(st_min[idx], st_max[idx]);
        } 
        if (r < L || R < l) {
            return T(2*n, -2*n);
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        auto [l_min, l_max] = query(l, mid, lson, L, R);
        auto [r_min, r_max] = query(mid+1, r, rson, L, R);
        return T(min(l_min, r_min), max(l_max, r_max));
    }
    void modify(int pos, int val) { modify(0, n-1, 1, pos, val); }
    T query(int L, int R) { return query(0, n-1, 1, L, R); }
};

void solve() {
    int n; cin >> n;
    map<int,vector<int>> D;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        D[d].emplace_back(i);
    }

    // find root
    int root = -1;
    if (D.count(0) == 0 || D[0].size() > 1) {
        cout << -1 << "\n"; return;
    } else {
        root = D[0].front();
        D.erase(D.begin());
    }

    // grow tree
    Seg1D seg(n);
    vector<int> pa(n, -1);
    vector<bool> vis(n, false);
    vector<int> dist;
    vis[root] = true;
    dist.emplace_back(root);
    auto good = [&](int u, int v) {
        if (u > v) swap(u, v);
        if (u+1 <= v-1) {
            auto [mn, mx] = seg.query(u+1, v-1);
            return u <= mn && mn <= v && u <= mx && mx <= v;
        } else {
            return true;
        }
    };
    for (int d = 1; d < n && !D.empty(); d++) {
        if (D.begin()->first == d) {
            auto &arr = D.begin()->second;
            for (auto v : arr) {
                // find the nearest vertex to plug
                auto it = upper_bound(dist.begin(), dist.end(), v);
                if (it != dist.end() && good(v, *it)) {
                    // connect v to *it
                    pa[v] = *it;
                    seg.modify(*it, v);
                    seg.modify(v, *it);
                } else if (it != dist.begin() && good(v, *(it-1))) {
                    // connect v to *(it-1)
                    it--;
                    pa[v] = *it;
                    seg.modify(*it, v);
                    seg.modify(v, *it);
                } else {
                    cout << -1 << "\n"; return;
                }
            }
            swap(dist, arr);
            sort(dist.begin(), dist.end());
            D.erase(D.begin());
        } else {
            dist.clear();
        }
    }

    // print tree
    for (int i = 0; i < n; i++) {
        if (pa[i] != -1) {
            cout << pa[i] + 1 << " " << i + 1 << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}

