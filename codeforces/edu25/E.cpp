#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int vn, en; cin >> vn >> en;
    vector<vector<int>> graph(vn);
    vector<int> indeg(vn, 0);
    for (int e = 0; e < en; e++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[v].emplace_back(u);
        indeg[u] += 1;
    }
    priority_queue<int> pq;
    for (int i = 0; i < vn; i++) {
        if (indeg[i] == 0) {
            pq.emplace(i);
        }
    }
    int label = vn;
    vector<int> ans(vn, 0);
    while (!pq.empty()) {
        int u = pq.top(); pq.pop();
        ans[u] = label, label--;
        for (auto v : graph[u]) {
            if (--indeg[v] == 0) {
                pq.emplace(v);
            }
        }
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

