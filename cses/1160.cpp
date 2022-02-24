#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<int> nxt;
vector<vector<int>> graph;
vector<vector<tuple<int,int>>> query;
vector<int> ans;

vector<bool> vis;
vector<int> instk, inpath, incyc;

void dfs(int u, int pa, int dep, int rt, int cyc_size) {
    vis[u] = true, inpath[u] = dep;

    // find answer
    for (auto [dest, ans_idx] : query[u]) {
        // case1: dest in path
        // case2: dest in cycle
        // case3: gg
        if (inpath[dest] != -1) {
            ans[ans_idx] = inpath[u] - inpath[dest];
        } else if (incyc[dest] != -1) {
            int dest_idx = incyc[dest] - incyc[rt];
            dest_idx += (dest_idx < 0? cyc_size : 0);
            if (0 <= dest_idx && dest_idx < cyc_size) {
                ans[ans_idx] = dep + dest_idx;
            } else {
                ans[ans_idx] = -1;
            }
        } else {
            ans[ans_idx] = -1;
        }
    }

    // dfs
    for (auto v : graph[u]) {
        if (v != pa) {
            dfs(v, u, dep + 1, rt, cyc_size);
        }
    }

    inpath[u] = -1;
}

void run(int u, int idx) {
    vis[u] = true, instk[u] = idx;

    int v = nxt[u];
    if (instk[v] != -1) {
        // I found a cycle
        int cyc_size = instk[u] - instk[v] + 1;
        for (int i = 0, x = v; i < cyc_size; i++, x = nxt[x]) {
            incyc[x] = i;
        }
        for (int i = 0, pa = u, rt = v; i < cyc_size; i++, pa = rt, rt = nxt[rt]) {
            dfs(rt, pa, 0, rt, cyc_size);
        }
        for (int i = 0, x = v; i < cyc_size; i++, x = nxt[x]) {
            incyc[x] = -1;
        }
    } else {
        run(v, idx + 1);
    }

    instk[u] = -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    nxt.assign(n, 0);
    graph.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> nxt[i]; nxt[i]--;
        graph[nxt[i]].emplace_back(i);
    }
    query.assign(n, vector<tuple<int,int>>());
    ans.assign(q, 0);
    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b; a--, b--;
        query[a].emplace_back(b, i);
    }
    // do something
    instk.assign(n, -1);
    inpath.assign(n, -1);
    incyc.assign(n, -1);
    vis.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) run(i, 0);
    }
    // ans
    for (auto x : ans) {
        cout << x << "\n";
    }
}
