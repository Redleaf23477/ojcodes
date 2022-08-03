#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<int,int>; // (weight, vertex)
using E3 = tuple<int,int,int>; // (weight, u, v)

struct DisjointSet {
    int vn;
    vector<int> pa;
    DisjointSet(int n): vn(n), pa(n) {
        iota(pa.begin(), pa.end(), 0);
    }
    int findrt(int u) {
        if (pa[u] == u) return u;
        else return pa[u] = findrt(pa[u]);
    }
    bool same(int u, int v) {
        return findrt(u) == findrt(v);
    }
    void uni(int u, int v) {
        pa[findrt(u)] = findrt(v);
    }
};

vector<vector<Edge>> kruskal(int vn, int en, vector<E3> &edge_list) {
    vector<E3> mst;
    DisjointSet ds(vn);
    sort(edge_list.begin(), edge_list.end());
    for (auto [w, u, v] : edge_list) {
        if (ds.same(u, v)) continue;
        mst.emplace_back(w, u, v);
        ds.uni(u, v);
    }

    vector<vector<Edge>> adj_list(vn);
    for (auto [w, u, v] : mst) {
        adj_list[u].emplace_back(w, v);
        adj_list[v].emplace_back(w, u);
    }
    return adj_list;
}

void solve(int vn, int en, int qn) {
    vector<E3> edge_list(en);
    for (auto &[w, u, v] : edge_list) {
        cin >> u >> v >> w; u--, v--;
    }

    // minimum spanning forest
    vector<vector<Edge>> mst = kruskal(vn, en, edge_list);

    // dfs find max edge for each (s, t) pair
    // note that since the tree is small, dfs will not TLE
    function<int(int,int,int)> max_edge = [&](int s, int p, int t) {
        if (s == t) return 0;
        for (auto [w, v] : mst[s]) {
            if (v == p) continue;
            int tmp = max_edge(v, s, t);
            if (tmp != -1) return max(tmp, w);
        }
        return -1;
    };
    for (int i = 0; i < qn; i++) {
        int u, v; cin >> u >> v; u--, v--;
        int ans = max_edge(u, u, v);
        if (ans == -1) cout << "no path\n";
        else cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int vn, en, qn, case_num = 0;
    while (cin >> vn >> en >> qn) {
        if (vn == 0 && en == 0 && qn == 0) break;
        if (case_num != 0) cout << "\n";
        cout << "Case #" << ++case_num << "\n";
        solve(vn, en, qn);
    }
}

