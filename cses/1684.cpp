#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void print_answer(int n, const vector<int> scc, const vector<vector<int>> &graph) {
    int scc_num = *max_element(scc.begin(), scc.end()) + 1;
    vector<vector<int>> dag(scc.size());
    vector<int> indeg(scc_num, 0), topo(scc_num, 0);
    for (int u = 1; u < 1 + 2*n; u++) {
        for (auto v : graph[u]) {
            int su = scc[u], sv = scc[v];
            if (su != sv) {
                dag[su].emplace_back(sv);
                indeg[sv]++;
            }
        }
    }
    queue<int> q; 
    for (int i = 0; i < scc_num; i++) {
        if (indeg[i] == 0) q.emplace(i);
    }
    for (int i = 0; !q.empty(); i++) {
        int u = q.front(); q.pop();
        topo[u] = i;
        for (auto v : dag[u]) {
            if (--indeg[v] == 0) {
                q.emplace(v);
            }
        }
    }
    vector<char> ass(n+1, 'x');
    for (int i = n+1; i <= n+n; i++) {
        if (topo[scc[i]] < topo[scc[i-n]]) ass[i-n] = '-';
        else ass[i-n] = '+';
    }
    for (int i = 1; i <= n; i++) {
        cout << ass[i] << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> m >> n;
    int vn = 1 + 2 * n;
    auto neg = [n](int x) { return (x > n? x-n : x+n); };
    vector<vector<int>> graph(vn); 
    for (int i = 0; i < m; i++) {
        vector<int> x(2);
        for (auto &xi : x) {
            char ch; cin >> ch;
            cin >> xi; xi += (ch == '+') * n;
        }
        graph[neg(x[0])].emplace_back(x[1]);
        graph[neg(x[1])].emplace_back(x[0]);
    }

    vector<int> scc(vn, -1), d(vn, -1), l(vn, -1), stk;
    vector<bool> instk(vn, false);
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
            sccidx++;
        }
    };
    for (int i = 0; i < vn; i++) {
        if (d[i] == -1) dfs(i);
    }

    // print answer
    bool good = true;
    for (int i = 1; i <= n && good; i++) {
        if (scc[i] == scc[neg(i)]) good = false;
    }
    if (good) {
        print_answer(n, scc, graph);
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

