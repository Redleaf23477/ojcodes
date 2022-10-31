#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg1D {
    int n;
    vector<int> const &arr;
    vector<LL> ans;
    vector<bool> tag;
    vector<LL> prefix01, prefix10;
    vector<LL> suffix01, suffix10;

    Seg1D(vector<int> const &arr, int _n) : n(_n), arr(arr), ans(4*n, 0), tag(4*n, false), 
                                            prefix01(4*n, 0), prefix10(4*n, 0), 
                                            suffix01(4*n, 0), suffix10(4*n, 0) {
        build(0, n-1, 1);
    }
    void up(int idx, int lson, int rson, int l, int r, int mid) {
        int left_len = mid - l + 1;
        int right_len = r - mid;
        // prefix
        prefix01[idx] = prefix01[lson];
        prefix10[idx] = prefix10[lson];
        if (prefix01[lson] == left_len) {
            prefix01[idx] += (left_len % 2 == 0? prefix01[rson] : prefix10[rson]);
        }
        if (prefix10[lson] == left_len) {
            prefix10[idx] += (left_len % 2 == 0? prefix10[rson] : prefix01[rson]);
        }
        // suffix
        suffix01[idx] = suffix01[rson];
        suffix10[idx] = suffix10[rson];
        if (suffix01[rson] == right_len) {
            suffix01[idx] += (right_len % 2 == 0? suffix01[lson] : suffix10[lson]);
        }
        if (suffix10[rson] == right_len) {
            suffix10[idx] += (right_len % 2 == 0? suffix10[lson] : suffix01[lson]);
        }
        // ans
        ans[idx] = ans[lson] + ans[rson];
        ans[idx] += suffix01[lson] * prefix10[rson];
        ans[idx] += suffix10[lson] * prefix01[rson];
    }
    void add_tag(int idx) {
        tag[idx] = !tag[idx];
        swap(prefix01[idx], prefix10[idx]);
        swap(suffix01[idx], suffix10[idx]);
    }
    void down(int idx, int lson, int rson) {
        if (tag[idx]) {
            add_tag(lson);
            add_tag(rson);
            tag[idx] = false;
        }
    }
    void build(int l, int r, int idx) {
        if (l == r) {
            ans[idx] = 1;
            if (arr[l] == 0) prefix01[idx] = suffix01[idx] = 1;
            else prefix10[idx] = suffix10[idx] = 1;
            return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson);
        build(mid+1, r, rson);
        up(idx, lson, rson, l, r, mid);
    }
    void flip(int l, int r) { flip(0, n-1, 1, l, r); }
    void flip(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            add_tag(idx); return;
        }
        if (r < L || R < l) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(idx, lson, rson);
        flip(l, mid, lson, L, R);
        flip(mid+1, r, rson, L, R);
        up(idx, lson, rson, l, r, mid);
    }
    LL query(int l, int r) { return query(0, n-1, 1, l, r); }
    LL query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) return ans[idx]; 
        if (r < L || R < l) return 0;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(idx, lson, rson);
        LL left_limit = max(0ll, mid - L + 1ll);
        LL right_limit = max(0ll, R - mid + 0ll);
        LL qry = query(l, mid, lson, L, R) + query(mid + 1, r, rson, L, R); 
        qry += min(left_limit, suffix01[lson]) * min(right_limit, prefix10[rson]);
        qry += min(left_limit, suffix10[lson]) * min(right_limit, prefix01[rson]);
        return qry;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<int> arr(n); 
    for (auto &x : arr) cin >> x;
    Seg1D seg(arr, n);
    while (q--) {
        int op, l, r; cin >> op >> l >> r; l--, r--;
        if (op == 1) {
            seg.flip(l, r);
        } else {
            cout << seg.query(l, r) << "\n";
        }
    }
}

