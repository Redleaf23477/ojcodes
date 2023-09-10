#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void mark_cycle(vector<vector<int>> const &graph, vector<int> &part, int N) {
    vector<bool> vis(N, false), instk(N, false);
    vector<int> stk;
    function<bool(int, int)> dfs = [&](int u, int pa) {
        vis[u] = true;
        instk[u] = true, stk.emplace_back(u);
        bool found_cycle = false;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            if (!vis[v]) {
                found_cycle = dfs(v, u);
                if (found_cycle) break;
            } else if (instk[v]) {
                for (auto it = stk.rbegin(); it != stk.rend(); it++) {
                    part[*it] = 0;
                    if (*it == v) break;
                }
                found_cycle = true;
                break;
            }
        }
        instk[u] = false, stk.pop_back();
        return found_cycle;
    };
    for (int i = 0; i < N; i++) {
        if (!vis[i]) {
            if (dfs(i, i) == true) return;
        }
    }
}

void mark_tree(int u, int idx, vector<vector<int>> const &graph, vector<int> &part) {
    function<void(int)> dfs = [&](int u) {
        part[u] = idx;
        for (auto v : graph[u]) {
            if (part[v] == -1) {
                dfs(v);
            }
        }
    };
    dfs(u);
}

void solve() {
    int N; cin >> N;
    vector<vector<int>> graph(N);
    for (int i = 0; i < N; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    // part = 0: cycle, later rewrite as root of each tree + 1
    vector<int> part(N, -1);
    mark_cycle(graph, part, N);
    for (int i = 0; i < N; i++) {
        if (part[i] == 0) {
            mark_tree(i, i + 1, graph, part);
        }
    }

    int Q; cin >> Q;
    while (Q--) {
        int u, v; cin >> u >> v; u--, v--;
        if (part[u] == part[v]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}