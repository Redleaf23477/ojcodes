#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

struct BIT {
    int n;
    vector<LL> arr;
    BIT(int _n): n(_n), arr(n, 0) {}
    int lowbit(int x) { return x & -x; }
    void modify(int x, LL val) {
        for (; x <= n; x += lowbit(x)) arr[x] += val;
    }
    LL query(int x) {
        LL sum = 0;
        for (; x; x -= lowbit(x)) sum += arr[x];
        return sum;
    }
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
    vector<LL> path_sum = arr;
    vector<int> in_time(n, 0), out_time(n, 0);
    function<void(int,int)> dfs = [&](int u, int pa) {
        static int ts = 0;
        in_time[u] = ++ts;
        if (u != pa) path_sum[u] += path_sum[pa];
        for (auto v : graph[u]) {
            if (v != pa) dfs(v, u);
        }
        out_time[u] = ts;
    };
    dfs(0, 0);
    BIT bit(n+2);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int s; cin >> s; s -= 1;
            LL x; cin >> x;
            LL diff = x - arr[s];
            bit.modify(in_time[s], diff);
            bit.modify(out_time[s] + 1, -diff);
            arr[s] = x;
        } else {
            int s; cin >> s; s -= 1;
            LL path = path_sum[s] + bit.query(in_time[s]);
            cout << path << "\n";
        }
    }
}