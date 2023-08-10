#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<LL,int>;
constexpr LL INF = 1e18;

void solve() {
    int N; cin >> N;
    vector<int> deg(N);
    for (auto &x : deg) cin >> x;
    vector<vector<Edge>> tree(N);
    for (int i = 1; i < N; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        tree[u].emplace_back(w, v);
        tree[v].emplace_back(w, u);
    }
    
    // dp[u][pick parent edge] = max weight
    vector dp(N, vector<LL>(2, 0));
    function<void(int,int)> dfs = [&](int u, int pa) {
        for (auto [w, v] : tree[u]) {
            if (v == pa) {
                dp[u][true] = w;
                continue;
            }
            dfs(v, u);
        }

        priority_queue<LL> pq;
        for (auto [w, v] : tree[u]) {
            if (v == pa) continue;
            dp[u][0] += dp[v][0];
            dp[u][1] += dp[v][0];
            pq.emplace(dp[v][1] - dp[v][0]);
        }

        int d = 0;
        while (!pq.empty() && pq.top() > 0) {
            if (d < deg[u]) dp[u][0] += pq.top();
            if (d + 1 < deg[u]) dp[u][1] += pq.top();
            d++, pq.pop();
        }
        if (deg[u] == 0) dp[u][1] = -INF;
    };
    dfs(0, 0);

    cout << dp[0][0] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



