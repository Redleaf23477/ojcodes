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
        bool is_input;
        Edge(int _v, T _f, int _re, bool inp=false) : v(_v), f(_f), re(_re), is_input(inp) {}
    };
    int n, s, t, level[MAXV];
    vector<Edge> E[MAXV];
    int now[MAXV];
    Dinic(int _n, int _s, int _t) : n(_n), s(_s), t(_t) {}
    void add_edge(int u, int v, T f, bool bidirectional = false) {
        E[u].emplace_back(v, f, E[v].size(), true);
        E[v].emplace_back(u, 0, E[u].size() - 1);
        if (bidirectional) {
            E[v].emplace_back(u, f, E[u].size() - 1, true);
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
    int s = 0, t = n + 1, vn = t + 1;
    Dinic<int> dinic(vn, s, t);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        dinic.add_edge(a, b, 1);
    }
    dinic.add_edge(s, 1, m);
    dinic.add_edge(n, t, m);
    int d = dinic.flow();

    vector<int> stk;
    function<void(int)> dfs = [&](int u) {
        stk.emplace_back(u);
        // cerr << "[stk] " << u << endl;
        if (u == n) {
            cout << stk.size() << "\n";
            for (size_t i = 0; i < stk.size(); i++) {
                cout << stk[i] << " ";
            }
            cout << "\n";
        } else {
            for (auto &e : dinic.E[u]) {
                auto &v = e.v, &f = e.f;
                auto &inp = e.is_input;
                if (e.is_input && f == 0) {
                    f -= 1;
                    dfs(v);
                    break;
                }
            }
        }
        stk.pop_back();
    };

    /*
    for (int i = 1; i <= n; i++) {
        cerr << i << " => ";
        for (auto x : dinic.E[i]) {
            if (x.is_input && x.f == 0) {
                cerr << x.v << " ";
            }
        }
        cerr << endl;
    }
    */

    cout << d << "\n";
    for (int i = 0; i < d; i++) {
        dfs(1);
    }
}
