#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<vector<int>> graph(n);
    vector<int> deg(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        deg[u] += 1, deg[v] += 1;
    }
    int leaf = -1;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) leaf = i;
    }
    vector<LL> ans(n, 0);

//    cerr << "leaf = " << leaf << ", pa = " << graph[leaf][0] << endl;
    
    function<bool(int,int,LL)> dfs = [&](int u, int pa, LL sub_sum) {
        for (auto v : graph[u]) {
            if (v == pa) continue;
            auto &x = sub_sum;
            auto &y = ans[u];
            auto &z = ans[v];
            z = x - (deg[v] - 1) * (y + (deg[u] - 1) * x);
            if (z == 0 || z < -100000 || z > 100000) return false;
            if (dfs(v, u, sub_sum - z) == false) return false;
        }
        return true;
    };

    // tiger blue plz don't hack me
    /*
    for (int i = -10; i <= 10; i++) if (i != 0) {
        for (int j = -10; j <= 10; j++) if (j != 0 && i+j != 0) {
            fill(ans.begin(), ans.end(), 0);
            ans[leaf] = i, ans[graph[leaf][0]] = j;
            if (dfs(graph[leaf][0], leaf, ans[leaf])) break;
        }
    }
    */
    ans[leaf] = -n, ans[graph[leaf][0]] = 1;
    dfs(graph[leaf][0], leaf, ans[leaf]);

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

