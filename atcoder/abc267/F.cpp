#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void preprocess_diameter(vector<vector<int>> const &graph,
                         vector<int> &diameter, vector<int> &parent_on_diameter,
                         int N) {
    vector<int> dep(N);
    function<int(int,int)> dfs = [&](int u, int pa) {
        if (u != pa) dep[u] = dep[pa] + 1;
        int farthest = u;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            int f = dfs(v, u);
            if (dep[f] > dep[farthest]) {
                farthest = f;
            }
        }
        return farthest;
    };
    function<bool(int,int,int)> get_diameter = [&](int u, int pa, int v) {
        diameter.emplace_back(u);
        if (u == v) return true;
        for (auto x : graph[u]) {
            if (x == pa) continue;
            if (get_diameter(x, u, v)) return true;
        }
        diameter.pop_back();
        return false;
    };
    function<void(int,int,int)> get_parent = [&](int u, int pa, int rt) {
        parent_on_diameter[u] = rt;
        for (auto v : graph[u]) {
            if (v == pa) continue;
            if (parent_on_diameter[v] != -1) continue;
            get_parent(v, u, rt);
        }
    };
    for (int i = 0; i < N; i++) {
        if (graph[i].size() == 1) {
            dep[i] = 0;
            int u = dfs(i, i);
            dep[u] = 0;
            int v = dfs(u, u);
            get_diameter(u, u, v);
            for (auto x : diameter) {
                parent_on_diameter[x] = x;
            }
            for (auto x : diameter) {
                get_parent(x, x, x);
            }
            break;
        }
    }
}

void run_offline(vector<vector<int>> const &graph, vector<int> const &diameter,
                 vector<int> const &parent_on_diameter,
                 vector<vector<pair<int, int>>> const &queries,
                 vector<int> &ans, int N) {
    vector<int> idx_on_diameter(N, -1);
    for (size_t i = 0; i < diameter.size(); i++) {
        idx_on_diameter[diameter[i]] = i;
    }

    vector<int> stk;
    auto solve_query_on_diameter = [&](int u, int k) {
        int idx = idx_on_diameter[u];
        if (idx >= k) return diameter[idx - k] + 1;
        else if (idx + k < (int)diameter.size()) return diameter[idx + k] + 1;
        else return -1;
    };
    auto solve_query = [&](int u, int k, int dep) {
        if (k < (int)stk.size()) {
            return stk[stk.size() - 1 - k] + 1;
        } else {
            return solve_query_on_diameter(parent_on_diameter[u], k - dep);
        }
    };
    function<void(int,int,int)> dfs = [&](int u, int pa, int dep) {
        stk.emplace_back(u);
        for (auto [k, qidx] : queries[u]) {
            if (dep == 0) {
                ans[qidx] = solve_query_on_diameter(u, k);
            } else {
                ans[qidx] = solve_query(u, k, dep);
            }
        }
        for (auto v : graph[u]) {
            if (v == pa) continue;
            dfs(v, u, dep + (parent_on_diameter[v] != v));
        }
        stk.pop_back();
    };
    int rt = diameter.front();
    dfs(rt, rt, 0);
}

void solve() {
    int N; cin >> N;
    vector<vector<int>> graph(N);
    for (int i = 1; i < N; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    
    // 1. find diameter
    // 2. rooted tree at a diameter, mark the parent on diameter
    vector<int> diameter;
    vector<int> parent_on_diameter(N, -1);
    preprocess_diameter(graph, diameter, parent_on_diameter, N);

/*
    cerr << "diameter: ";
    for (auto x : diameter) cerr << x + 1 << " ";
    cerr << endl;
    cerr << "parent on diameter: ";
    for (auto x : parent_on_diameter) cerr << x + 1 << " ";
    cerr << endl;
*/

    // 3. offline solve the queries
    int Q; cin >> Q;
    vector<int> ans(Q);
    vector<vector<pair<int,int>>> queries(N); // queries[u] = {(k, qidx)}
    for (int i = 0; i < Q; i++) {
        int u, k; cin >> u >> k; u--;
        queries[u].emplace_back(k, i);
    }
    run_offline(graph, diameter, parent_on_diameter, queries, ans, N);

    for (auto x : ans) cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}