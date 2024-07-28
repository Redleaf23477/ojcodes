#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL INF = 1ll << 60;
using Edge = pair<LL,LL>;

vector<LL> run_dijk(vector<vector<Edge>> &G) {
    int n = G.size();
    vector<LL> dist(n, INF);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

    dist[0] = 0;
    pq.emplace(0, 0);

    while (!pq.empty()) {
        auto [len, u] = pq.top(); pq.pop();
        if (len > dist[u]) continue;

        for (auto [w, v] : G[u]) {
            LL new_len = len + w;
            if (new_len < dist[v]) {
                dist[v] = new_len;
                pq.emplace(new_len, v);
            }
        }
    }

    return dist;
}

void solve() {
    int N; cin >> N;
    int M; cin >> M;
    vector<LL> A(N);
    for (auto &x : A) cin >> x;

    int vn = 2 * N;
    vector<vector<Edge>> G(vn);
    for (int i = 0; i < N; i++) {
        int u = i, v = i + N;
        G[u].emplace_back(A[i], v);
    }
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        G[u + N].emplace_back(w, v);
        G[v + N].emplace_back(w, u);
    }

    auto sssp = run_dijk(G);
    for (int i = 1; i < N; i++) {
        cout << sssp[i + N] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

