#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<int,int,LL>;

struct DisjointSet {
    int n;
    vector<int> pa, sz;
    DisjointSet(int _n) : n(_n), pa(n, 0), sz(n, 1) {
        iota(pa.begin(), pa.end(), 0);
    }
    int findrt(int x) {
        if (pa[x] == x) return x;
        else return pa[x] = findrt(pa[x]);
    }
    bool same(int x, int y) {
        return findrt(x) == findrt(y);
    }
    void uni(int x, int y) {
        if (same(x, y)) return;
        x = findrt(x), y = findrt(y);
        if (sz[x] < sz[y]) swap(x, y);
        pa[y] = x;
        sz[x] += sz[y];
    }
    int get_size(int x) {
        return sz[findrt(x)];
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<Edge> edge_list(m);
    for (auto &[u, v, w] : edge_list) {
        cin >> u >> v >> w; u--, v--;
    }
    sort(edge_list.begin(), edge_list.end(), [](const Edge &lhs, const Edge &rhs) {
        return get<2>(lhs) < get<2>(rhs);
    });
    LL ans = 0;
    DisjointSet ds(n);
    for (auto [u, v, w] : edge_list) {
        if (ds.same(u, v)) continue;
        ans += w;
        ds.uni(u, v);
    }
    if (ds.get_size(0) == n) {
        cout << ans << "\n";
    } else {
        cout << "IMPOSSIBLE\n";
    }
}