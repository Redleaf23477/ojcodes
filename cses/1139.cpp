#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> color(n);
    for (auto &x : color) cin >> x;
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<int> ans(n, 0);
    function<set<int>(int,int)> dfs = [&](int u, int pa) {
        set<int> ans_set({color[u]});
        for (auto v : graph[u]) if (pa != v) {
            auto s = dfs(v, u);
            if (s.size() > ans_set.size()) swap(s, ans_set);
            ans_set.insert(s.begin(), s.end());
        }
        ans[u] = ans_set.size();
        return ans_set;
    };
    dfs(0, 0);
    for (auto x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

