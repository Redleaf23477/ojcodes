#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<bool> vis(N + 1, false);
    vector<int> stk;
    function<LL(int,int)> bfs = [&](int u, int k) {
        queue<int> q, next_q;
        q.emplace(u), vis[u] = true, stk.emplace_back(u);
        while (k--) {
            while (!q.empty()) {
                u = q.front(); q.pop();
                for (auto v : graph[u]) {
                    if (vis[v]) continue;
                    next_q.emplace(v), vis[v] = true, stk.emplace_back(v);
                }
            }
            swap(q, next_q);
        }
        LL ans = accumulate(stk.begin(), stk.end(), 0ll);
        for (auto x : stk) vis[x] = false;
        stk.clear();
        return ans;
    };
    int Q; cin >> Q;
    while (Q--) {
        int x, k; cin >> x >> k;
        cout << bfs(x, k) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



