#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int n, k;
vector<vector<int>> graph;

vector<int> t_size;
vector<bool> rm_vertex;

int find_centroid(int u, int subtree_size) {
    int centroid = -1;  // find any centroid
    function<void(int,int)> dfs_c = [&](int u, int pa) {
        int max_subtree_size = 0;
        t_size[u] = 1;
        for (auto v : graph[u]) if (v != pa && !rm_vertex[v]) {
            dfs_c(v, u);
            max_subtree_size = max(max_subtree_size, t_size[v]);
            t_size[u] += t_size[v];
        }
        if (pa != u) {
            int pa_sz = subtree_size - t_size[u];
            max_subtree_size = max(max_subtree_size, pa_sz);
        }
        if (max_subtree_size <= subtree_size / 2) {
            centroid = u;
        }
    };
    dfs_c(u, u);
    return centroid;
}

void calc_subtree_size(int u) {
    function<void(int,int)> dfs_s = [&](int u, int pa) {
        t_size[u] = 1;
        for (auto v : graph[u]) if (v != pa && !rm_vertex[v]) {
            dfs_s(v, u);
            t_size[u] += t_size[v];
        }
    };
    dfs_s(u, u);
}

LL calc(int u) {
    map<int,LL> sub_dep;
    function<void(int,int,int)> dfs_d = [&](int u, int pa, int d) {
        sub_dep[d] += 1;
        for (auto v : graph[u]) if (v != pa && !rm_vertex[v]) {
            dfs_d(v, u, d+1);
        }
    };
    LL ans = 0;
    vector<LL> dep(t_size[u] + 1, 0);
    dep[0] = 1;
    for (auto v : graph[u]) if (!rm_vertex[v]) {
        sub_dep.clear();
        dfs_d(v, u, 1);
        for (auto [d, cnt] : sub_dep) {
            int d2 = k - d;
            if (t_size[u] >= d2 && d2 >= 0) ans += cnt * dep[d2];
        }
        for (auto [d, cnt] : sub_dep) {
            dep[d] += cnt;
        }
    }
    return ans;
}

LL dfs(int u) {
    LL ans = 0;
    // this subtree
    calc_subtree_size(u);
    ans += calc(u);
    // further subtrees
    rm_vertex[u] = true;
    for (auto v : graph[u]) if (!rm_vertex[v]) {
        int c = find_centroid(v, t_size[v]);
        ans += dfs(c);
    }
    return ans;
}


int main() {
    ios::sync_with_stdio(false); cin.tie();
    cin >> n >> k;
    graph.assign(n, vector<int>());
    t_size.assign(n, 0);
    rm_vertex.assign(n, false);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    int c = find_centroid(0, n);
    LL ans = dfs(c);
    cout << ans << "\n";
}

