#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct BIT {
    int n;
    vector<LL> bit;
    BIT(int _n): n(_n), bit(n+1, 0) {}
    int lowbit(int x) { return x & -x; }
    void modify(int x, LL val) {
        for (; x <= n; x += lowbit(x)) 
            bit[x] += val;
    }
    LL query(int x) {
        LL ans = 0;
        for (; x; x -= lowbit(x)) 
            ans += bit[x];
        return ans;
    }
};

int n, k1, k2;
vector<vector<int>> graph;

vector<int> t_size;
vector<bool> rm_vertex;

int find_centroid(int u, int subtree_size) {
    int centroid = -1, cp = -1;  // find any centroid
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
            centroid = u, cp = pa;
        }
    };
    dfs_c(u, u);
    // make sure t_size[v] is correct for children of returned centroid
    if (cp != centroid) {
        t_size[cp] = subtree_size;
        for (auto v : graph[centroid]) if (v != cp && !rm_vertex[v]) {
            t_size[cp] -= t_size[v];
        }
    }
    return centroid;
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
    BIT bit(t_size[u]);
    for (auto v : graph[u]) if (!rm_vertex[v]) {
        sub_dep.clear();
        dfs_d(v, u, 1);
        for (auto [d, cnt] : sub_dep) {
            int low = min(t_size[u], k1 - d), high = min(t_size[u], k2 - d);
            if (high > 0) ans += cnt * bit.query(high);
            if (high >= 0) ans += cnt * 1;
            if (low-1 > 0) ans -= cnt * bit.query(low-1);
            if (low-1 >= 0) ans -= cnt * 1;
        }
        for (auto [d, cnt] : sub_dep) {
            bit.modify(d, cnt);
        }
    }
    return ans;
}

LL dfs(int u) {
    LL ans = 0;
    // this subtree
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
    cin >> n >> k1 >> k2;
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

