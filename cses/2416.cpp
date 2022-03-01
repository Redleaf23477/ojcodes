#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct Seg1D {
    int n;
    using Node = tuple<LL,LL>;  // (val, tag), -1 := no tag
    vector<Node> st;

    void up(Node &rt, Node &lchild, Node &rchild) {
        const auto &[l_sum, l_tag] = lchild;
        const auto &[r_sum, r_tag] = rchild;
        rt = Node(l_sum + r_sum, -1);
    }

    void down(Node &rt, Node &lchild, Node &rchild, int l_len, int r_len) {
        auto &[sum, tag] = rt;
        auto &[l_sum, l_tag] = lchild;
        auto &[r_sum, r_tag] = rchild;
        if (tag != -1) {
            l_sum = l_len * tag, l_tag = tag;
            r_sum = r_len * tag, r_tag = tag;
            tag = -1;
        }
    }

    void build(int l, int r, int idx, const vector<LL> &arr) {
        if (l == r) {
            st[idx] = Node(arr[l], -1); return;
        }
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        build(l, mid, lson, arr);
        build(mid+1, r, rson, arr);
        up(st[idx], st[lson], st[rson]);
    }

    void add_tag(int l, int r, int idx, int L, int R, LL val) {
        if (L <= l && r <= R) {
            auto &[sum, tag] = st[idx];
            sum = val * (r - l + 1);
            tag = val;
            return;
        } else if (r < L || R < l) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(st[idx], st[lson], st[rson], mid - l + 1, r - mid);
        add_tag(l, mid, lson, L, R, val);
        add_tag(mid+1, r, rson, L, R, val);
        up(st[idx], st[lson], st[rson]);
    }

    void add_tag(int L, int R, LL val) { add_tag(0, n-1, 1, L, R, val); }

    LL query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) {
            auto &[sum, tag] = st[idx];
            return sum;
        } else if (r < L || R < l) return 0;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        down(st[idx], st[lson], st[rson], mid - l + 1, r - mid);
        return query(l, mid, lson, L, R) + query(mid+1, r, rson, L, R);
    }

    LL query(int L, int R) { return query(0, n-1, 1, L, R); }

    Seg1D(int _n, const vector<LL> &arr) : n(_n), st(4*n) {
        build(0, n-1, 1, arr);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    // note: arr is 1-index
    int n, q; cin >> n >> q;
    vector<LL> arr(n+1, 0), pre_sum(n+1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    partial_sum(arr.begin(), arr.end(), pre_sum.begin());
    
    using Q = tuple<int,int,int>;  // (l, r, idx)
    vector<Q> query(q);
    for (int i = 0; i < q; i++) {
        auto &[l, r, idx] = query[i];
        cin >> l >> r;
        idx = i;
    }
    sort(query.begin(), query.end(), [](const Q &lhs, const Q &rhs) {
        const auto &[l1, r1, i1] = lhs;
        const auto &[l2, r2, i2] = rhs;
        if (l1 != l2) return l1 > l2;
        else if (r1 != r2) return r1 > r2;
        else return i1 > i2;
    });

    vector<LL> ans(q);
    Seg1D seg(n+1, arr);
    int L = n;
    stack<int> stk({n});
    for (auto [l, r, idx] : query) {
        for (; L >= l; L--) {
            while (!stk.empty() && arr[L] >= arr[stk.top()]) stk.pop();
            int R = (stk.empty()? n : stk.top() - 1);
            seg.add_tag(L, R, arr[L]);
            stk.emplace(L);
        }
        ans[idx] = seg.query(l, r) - (pre_sum[r] - pre_sum[l-1]);
    }

    for (auto x : ans) cout << x << "\n";
}