#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

struct Seg1D {
    int n;
    vector<LL> st;
    Seg1D(int _n): n(_n), st(4*n, 0) {}
    void modify(int l, int r, int idx, int x, LL val) {
        if (l == x && r == x) {
            st[idx] = val; return;
        } else if (x < l || r < x) return;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        modify(l, mid, lson, x, val);
        modify(mid+1, r, rson, x, val);
        st[idx] = st[lson] + st[rson];
    }
    void modify(int x, LL val) { modify(0, n-1, 1, x, val); }
    LL query(int l, int r, int idx, int L, int R) {
        if (L <= l && r <= R) return st[idx];
        else if (r < L || R < l) return 0;
        int mid = (l + r) / 2, lson = idx * 2, rson = idx * 2 + 1;
        return query(l, mid, lson, L, R) + query(mid+1, r, rson, L, R);
    }
    LL query(int L, int R) { return query(0, n-1, 1, L, R); }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<int> in_time(n, 0), out_time(n, 0);
    function<void(int,int)> dfs = [&](int u, int pa) {
        static int ts = -1;
        in_time[u] = ++ts;
        for (auto v : graph[u]) {
            if (v != pa) dfs(v, u);
        }
        out_time[u] = ts;
    };
    dfs(0, 0);
    Seg1D st(n);
    for (int i = 0; i < n; i++) {
        st.modify(in_time[i], arr[i]);
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int s; cin >> s; s -= 1;
            LL x; cin >> x;
            st.modify(in_time[s], x);
        } else {
            int s; cin >> s; s -= 1;
            cout << st.query(in_time[s], out_time[s]) << "\n";
        }
    }
}