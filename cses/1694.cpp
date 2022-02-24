#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

template <class T>
struct Dinic {
    static const int MAXV = 10000;
    static const T INF = 1e18;
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
    int n, m; cin >> n >> m;
    vector<vector<bool>> is_edge(n, vector<bool>(n, false));
    Dinic<LL> dinic(n, 0, n-1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        is_edge[u][v] = is_edge[v][u] = true;
        dinic.add_edge(u, v, 1, true);
    }
    vector<bool> vis1(n, false), vis2(n, false);
    function<void(int)> dfs1 = [&](int u) {
        vis1[u] = true;
        for (auto [v, f, _] : dinic.E[u]) {
            if (is_edge[u][v] && f > 0 && !vis1[v]) {
                dfs1(v);
            }
        }
    };
    function<void(int)> dfs2 = [&](int u) {
        vis2[u] = true;
        for (auto [v, f, _] : dinic.E[u]) {
            if (is_edge[u][v] && !vis1[v]) {
                int a = u+1, b = v+1;
                if (a > b) swap(a, b);
                cout << a << " " << b << "\n";
            }
            if (is_edge[u][v] && f > 0 && !vis2[v]) {
                dfs2(v);
            }
        }
    };
    cout << dinic.flow() << "\n";
    dfs1(0);
    dfs2(0);
}

