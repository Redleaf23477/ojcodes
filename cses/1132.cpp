#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> graph(n);
    vector<int> indeg(n, 0);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        indeg[u]++, indeg[v]++;
    }
    vector<int> dist(n, 0), ans(n, 0);
    function<void(int,int)> dfs1 = [&](int u, int pa) {
        for (auto v : graph[u]) {
            if (v == pa) continue;
            dfs1(v, u);
            dist[u] = max(dist[u], dist[v] + 1);
        }
        ans[u] = dist[u];
    };
    function<void(int,int,int)> dfs2 = [&](int u, int pa, int pa_ans) {
        ans[u] = max(ans[u], pa_ans);
        vector<int> mx(2, 0); mx[0] = pa_ans;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            if (dist[v]+1 >= mx[0]) mx[1] = mx[0], mx[0] = dist[v]+1;
            else if (dist[v]+1 >= mx[1]) mx[1] = dist[v]+1;
        }
        //cerr << "u = " << u << ", pa_ans = " << pa_ans << ", mx = " << mx[0] << ", " << mx[1] << endl;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            if (dist[v]+1 == mx[0]) dfs2(v, u, mx[1]+1);
            else dfs2(v, u, mx[0]+1);
        }
    };
    dfs1(0, 0);
    dfs2(0, 0, 0);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}