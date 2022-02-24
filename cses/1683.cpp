#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
    }

    vector<int> scc(n, -1), d(n, -1), l(n, -1), stk;
    vector<bool> instk(n, false);
    int timestamp = 0, sccidx = 1;
    function<void(int)> dfs = [&](int u) {
        d[u] = l[u] = timestamp++;
        stk.emplace_back(u), instk[u] = true;

        for (auto v : graph[u]) {
            if (d[v] == -1) {  // not visited
                dfs(v);
                l[u] = min(l[u], l[v]);
            } else if (instk[v]) {
                l[u] = min(l[u], d[v]);
            }
        }

        if (l[u] == d[u]) {  // report scc
            int x;
            do {
                x = stk.back(); stk.pop_back();
                scc[x] = sccidx;
                instk[x] = false;
            } while (x != u); 
            sccidx++;
        }
    };
    for (int i = 0; i < n; i++) {
        if (d[i] == -1) dfs(i);
    }
    cout << sccidx-1 << "\n";
    for (auto x : scc) cout << x << " "; 
    cout << "\n";
}

