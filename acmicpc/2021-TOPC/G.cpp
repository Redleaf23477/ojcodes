#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<int,int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    map<int, vector<Edge>> edges;
    for (int i = 1; i < n; i++) {
        int u, v, len; cin >> u >> v >> len; u--, v--;
        edges[len].emplace_back(u, v);
    }
    vector<LL> dp(n, 0);
    for (const auto &[len, edge_set] : edges) {
        // update dp
        map<int,LL> upd;
        for (const auto &[u, v] : edge_set) {
            upd[u] += 1 + dp[v];
            upd[v] += 1 + dp[u];
        }
        for (auto [x , val] : upd) {
            dp[x] += val;
        }
    }
    cout << accumulate(dp.begin(), dp.end(), 0ll) << "\n";
}

