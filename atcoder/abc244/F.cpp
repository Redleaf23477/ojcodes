#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, M; cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    vector<vector<int>> sp(1 << N, vector<int>(N, 1 << N));
    queue<pair<int,int>> Q;
    for (int u = 0; u < N; u++) {
        sp[0][u] = 0;
        Q.emplace(0, u);
    }
    while (!Q.empty()) {
        auto [s, u] = Q.front(); Q.pop();
        for (auto v : graph[u]) {
            int s2 = s ^ (1 << v);
            if (sp[s2][v] > sp[s][u] + 1) {
                sp[s2][v] = sp[s][u] + 1;
                Q.emplace(s2, v);
            }
        }
    }
    int ans = 0;
    for (int s = 0; s < (1 << N); s++) {
        ans += *min_element(sp[s].begin(), sp[s].end());
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



