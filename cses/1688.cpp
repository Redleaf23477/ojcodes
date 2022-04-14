#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    int lgn = log2(n) + 1;
    vector<vector<int>> graph(n);
    vector<vector<int>> dp(lgn+1, vector<int>(n, 0));
    dp[0][0] = -1;
    for (int i = 1; i < n; i++) {
        int pa; cin >> pa; pa--;
        dp[0][i] = pa;
        graph[pa].emplace_back(i);
    }
    for (int k = 1; k <= lgn; k++) for (int i = 0; i < n; i++) {
        if (dp[k-1][i] == -1) dp[k][i] = -1;
        else dp[k][i] = dp[k-1][dp[k-1][i]];
    }
    vector<int> dep(n, 0);
    function<void(int,int)> dfs = [&](int u, int pa) {
        for (auto v : graph[u]) {
            if (v == pa) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    };
    dfs(0, 0);
    auto jump = [&](int x, int dist) {
        for (int i = 0; (dist >> i); i++) {
            if ((dist >> i) & 1) {
                x = dp[i][x];
            }
        }
        return x;
    };
    while (q--) {
        int x, y; cin >> x >> y; x--, y--;
        if (dep[x] > dep[y]) swap(x, y);
        // jump y to same dep as x
        int diff = dep[y] - dep[x];
        y = jump(y, diff);
        // binary search lca
        int low = 0, high = dep[x], mid, lca = -1;
        while (low <= high) {
            mid = (low + high) / 2;
            int xp = jump(x, mid), yp = jump(y, mid);
            if (xp == yp) lca = xp + 1, high = mid - 1;
            else low = mid + 1;
        }
        cout << lca << "\n";
    }
}