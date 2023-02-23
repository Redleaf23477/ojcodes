#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vector<vector<int>> graph(n+1);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        graph[l-1].emplace_back(r);
        graph[r].emplace_back(l-1);
    }
    vector<bool> vis(n+1, false);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v : graph[u]) {
            if (!vis[v]) dfs(v);
        }
    };
    dfs(0);
    cout << (vis[n]? "Yes\n" : "No\n"); 
}

