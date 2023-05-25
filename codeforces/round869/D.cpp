#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int caseN = 0;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> deg(n, 0);
    for (int e = 0; e < m; e++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
        deg[u]++, deg[v]++;
    }
    vector<bool> vis(n, false);
    vector<int> instk(n, -1);
    vector<int> stk;
    function<bool(int,int,int)> find_cycle = [&](int u, int pa, int root) {
        vis[u] = true;
        instk[u] = stk.size();
        stk.emplace_back(u);
        for (auto v : graph[u]) {
            if (v == pa) continue;
            if (v == root) {
                // found cycle: the vertices in stk
                vector<int> tail;
                for (auto x : graph[root]) {
                    if (x == stk[1] || x == stk.back()) continue;
                    tail.emplace_back(x);
                    if (tail.size() == 2) break;
                }
                // rebuild fish
                if (instk[tail[0]] == -1 || (instk[tail[1]] != -1 && instk[tail[1]] < instk[tail[0]])) swap(tail[0], tail[1]);
                if (instk[tail[0]] != -1) {
                    int x = tail[0];
                    tail = vector<int>{(int)stk.back(), tail[1]};
                    stk.erase(stk.begin() + instk[x] + 1, stk.end());
                }
                // print
                cout << "YES\n";
                cout << stk.size() + 2 << "\n";
                for (auto x : tail) cout << root+1 << " " << x+1 << "\n";
                for (size_t i = 1; i < stk.size(); i++) cout << stk[i]+1 << " " << stk[i-1]+1 << "\n";
                cout << stk.front()+1 << " " << stk.back()+1 << "\n";
                return true;
            } else if (!vis[v]) {
                bool res = find_cycle(v, u, root);
                if (res) return res;
            }
        }
        instk[u] = -1;
        stk.pop_back();
        return false;
    };
    for (int root = 0; root < n; root++) {
        if (deg[root] >= 4) {
            vis.assign(n, false);
            if (find_cycle(root, root, root)) {
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        ++caseN;
        solve();
    }
}



