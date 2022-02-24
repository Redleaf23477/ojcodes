#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<int> find_scc(const vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> scc(n, -1), d(n, -1), l(n, -1), stk;
    vector<bool> instk(n, false);
    int timestamp = 0, sccidx = 0;
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
            sccidx += 1;
        }
    };
    for (int i = 0; i < n; i++) {
        if (d[i] == -1) dfs(i);
    }

    return scc;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
    }

    // find scc and build dag
    vector<int> scc = find_scc(graph);
    int scc_num = *max_element(scc.begin(), scc.end()) + 1;
    vector<set<int>> scc_graph(scc.size());
    vector<int> scc_indeg(scc.size(), 0);
    for (int u = 0; u < n; u++) {
        for (auto v : graph[u]) {
            if (scc[u] != scc[v] && scc_graph[scc[u]].count(scc[v]) == 0) {
                scc_graph[scc[u]].insert(scc[v]);
                scc_indeg[scc[v]] += 1;
            }
        }
    }

    /*
    for (auto x : scc) {
        cerr << x << " ";
    }
    cerr << endl;
    */

    // topological sort & answer
    vector<LL> acc(scc_num, 0), ans(scc_num, 0);
    for (int i = 0; i < n; i++) {
        acc[scc[i]] += arr[i];
    }
    queue<int> q;
    for (int i = 0; i < scc_num; i++) {
        if (scc_indeg[i] == 0) {
            q.emplace(i);
            ans[i] = acc[i];
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : scc_graph[u]) {
            ans[v] = max(ans[v], ans[u] + acc[v]);
            if (--scc_indeg[v] == 0) q.emplace(v);
        }
    }

    cout << *max_element(ans.begin(), ans.end()) << "\n";
}

