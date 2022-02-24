#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

template <class T>
struct Dinic {
    static const int MAXV = 10000;
    static const T INF = 1e9;
    struct Edge {
        int v;
        T f;
        int re;
        Edge(int _v, T _f, int _re) : v(_v), f(_f), re(_re) {}
    };
    int n, s, t, level[MAXV];
    vector<Edge> E[MAXV];
    int now[MAXV];
    Dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {}
    void add_edge(int u, int v, T f, bool bidirectional = false) {
        E[u].emplace_back(v, f, E[v].size());
        E[v].emplace_back(u, 0, E[u].size() - 1);
        if (bidirectional) {
            E[v].emplace_back(u, f, E[u].size() - 1);
        }
    }
    bool BFS() {
        memset(level, -1, sizeof(level));
        queue<int> que;
        que.emplace(s);
        level[s] = 0;
        while (not que.empty()) {
            int u = que.front();
            que.pop();
            for (auto it : E[u]) {
                if (it.f > 0 and level[it.v] == -1) {
                    level[it.v] = level[u] + 1;
                    que.emplace(it.v);
                }
            }
        }
        return level[t] != -1;
    }
    T DFS(int u, T nf) {
        if (u == t) return nf;
        T res = 0;
        while (now[u] < E[u].size()) {
            Edge &it = E[u][now[u]];
            if (it.f > 0 and level[it.v] == level[u] + 1) {
                T tf = DFS(it.v, min(nf, it.f));
                res += tf;
                nf -= tf;
                it.f -= tf;
                E[it.v][it.re].f += tf;
                if (nf == 0) return res;
            } else
                ++now[u];
        }
        if (not res) level[u] = -1;
        return res;
    }
    T flow(T res = 0) {
        while (BFS()) {
            T temp;
            memset(now, 0, sizeof(now));
            while (temp = DFS(s, INF)) {
                res += temp;
                res = min(res, INF);
            }
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m, k; cin >> n >> m >> k;
    int s = 0, t = n + m + 1, vn = t + 1;
    Dinic<int> dinic(vn, s, t);
    for (int i = 0; i < n; i++) {
        dinic.add_edge(s, i+1, 1);
    }
    for (int i = 0; i < m; i++) {
        dinic.add_edge(n+i+1, t, 1);
    }
    vector<vector<bool>> is_edge(n+1, vector<bool>(m+1, false));
    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v; v += n;
        is_edge[u][v-n] = true;
        dinic.add_edge(u, v, 1);
    }
    cout << dinic.flow() << "\n";
    for (int u = 1; u <= n; u++) {
        for (auto [v, f, _] : dinic.E[u]) {
            if (v-n > 0 && is_edge[u][v-n] && f == 0) {
                cout << u << " " << v-n << "\n";
            }
        }
    }
}