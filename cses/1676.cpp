#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<int,int,LL>;

struct DisjointSet {
    int n, cnt, mx_sz;
    vector<int> pa, sz;
    DisjointSet(int _n) : n(_n), cnt(n), mx_sz(1), pa(n, 0), sz(n, 1) {
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
        cnt -= 1;
        mx_sz = max(sz[x], mx_sz);
    }
    void print_ans() {
        cout << cnt << " " << mx_sz << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    DisjointSet ds(n);
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v; u--, v--;
        ds.uni(u, v);
        ds.print_ans();
    }
}