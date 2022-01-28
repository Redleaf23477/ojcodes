#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct DisjointSet {
    int n; 
    int mx_sz;
    vector<int> pa, sz;
    DisjointSet(int _n) : n(_n), mx_sz(1), pa(n), sz(n, 1) {
        iota(pa.begin(), pa.end(), 0);
    }
    int findrt(int x) {
        if (x == pa[x]) return x;
        else return pa[x] = findrt(pa[x]);
    }
    bool same(int x, int y) {
        return findrt(x) == findrt(y); 
    }
    void uni(int x, int y) {
        if (same(x, y)) return;
        int rx = findrt(x), ry = findrt(y);
        pa[rx] = ry;
        sz[ry] += sz[rx];
        mx_sz = max(mx_sz, sz[ry]);
    }
    int get_max_size() { return mx_sz; }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        DisjointSet dsu(n+1);
        while (m--) {
            int u, v; cin >> u >> v;
            dsu.uni(u, v);
        }
        cout << dsu.get_max_size() << "\n";
    }
}

