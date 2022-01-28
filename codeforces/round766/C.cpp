#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<vector<tuple<int,int>>> graph(n);
    vector<int> deg(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v, i-1);
        graph[v].emplace_back(u, i-1);
        deg[u] += 1, deg[v] += 1;
    }
    // if not path, no solution
    for (auto d : deg) {
        if (d >= 3) {
            cout << -1 << "\n";
            return;
        }
    }
    // find a leaf and assign
    vector<int> ans(n-1, 0);
    function<void(int,int,bool)> dfs = [&](int u, int pa, bool flag) {
        for (auto [v, idx] : graph[u]) {
            if (v == pa) continue;
            if (flag) {
                ans[idx] = 2;
            } else {
                ans[idx] = 3;
            }
            dfs(v, u, !flag);
        }
    };
    for (int u = 0; u < n; u++) {
        if (deg[u] != 1) continue;
        dfs(u, u, true);
        // assigned answer, break
        break;
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

