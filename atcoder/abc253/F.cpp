#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct BIT {
    int n;
    vector<LL> bit;
    BIT(int _n) : n(_n + 1), bit(n, 0) {}
    int lowbit(int x) { return x & (-x); }
    void add(int x, LL val) {
        for (; x < n; x += lowbit(x)) {
            bit[x] += val;
        }
    }
    LL sum(int x) {
        LL ans = 0;
        for (; x > 0; x -= lowbit(x)) {
            ans += bit[x];
        }
        return ans;
    }
};

void solve() {
    int N, M, Q; cin >> N >> M >> Q;
    BIT bit(M);
    vector<LL> ans;
    vector<int> op_set_row(N + 1, -1);
    vector<vector<int>> query(Q);
    // input and preprocess
    for (int i = 0; i < Q; i++) {
        auto &qry = query[i];
        int op; cin >> op;
        if (op == 1) {
            // {op, l, r, x}
            int l, r, x; cin >> l >> r >> x;
            qry = vector<int> {op, l, r, x};
        } else if (op == 2) {
            // {op, r, x, ...(I should push to which query type 3)...}
            int r, x; cin >> r >> x;
            qry = vector<int> {op, r, x};
            op_set_row[r] = i;
        } else {
            // {op, r, c, ans_idx}
            int r, c; cin >> r >> c;
            qry = vector<int> {op, r, c, (int)ans.size()};
            if (op_set_row[r] != -1) {
                query[op_set_row[r]].emplace_back(i);
            }
            ans.emplace_back(0);
        }
    }
    // run
    for (auto &qry : query) {
        int op = qry[0];
        if (op == 1) {
            int l = qry[1], r = qry[2], x = qry[3];
            bit.add(l, x);
            bit.add(r + 1, -x);
        } else if (op == 2) {
            int x = qry[2];
            for (size_t i = 3; i < qry.size(); i++) {
                int dest = qry[i];
                int dest_c = query[dest][2];
                int dest_ans_idx = query[dest][3];
                LL val = bit.sum(dest_c);
                ans[dest_ans_idx] = x - val;
            }
        } else {
            int c = qry[2], ans_idx = qry[3];
            LL val = bit.sum(c);
            ans[ans_idx] += val;
        }
    }
    // print answer
    for (auto x : ans) {
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



