#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct DisjointSet {
    // 0-index
    int n; 
    vector<int> pa;
    DisjointSet(int _n) : n(_n), pa(n) {
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
        pa[findrt(x)] = findrt(y);
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m, q; cin >> n >> m >> q;
    using Edge = tuple<int, int, int, int>;  // (weight, u, v, qidx)
    vector<Edge> arr(m + q);
    for (int i = 0; i < m; i++) {
        auto &[w, u, v, qidx] = arr[i];
        cin >> u >> v >> w;
        u--, v--;
        qidx = -1;
    }
    for (int i = 0; i < q; i++) {
        auto &[w, u, v, qidx] = arr[m+i];
        cin >> u >> v >> w;
        u--, v--;
        qidx = i;
    }
    sort(arr.begin(), arr.end());
    vector<bool> ans(q, false);
    // Kruskal
    DisjointSet ds(n);
    for (const auto [w, u, v, qidx] : arr) {
        if (!ds.same(u, v)) {
            if (qidx == -1) {
                ds.uni(u, v);
            } else {
                ans[qidx] = true;
            }
        }
    }
    for (auto x : ans) {
        if (x) cout << "Yes\n";
        else cout << "No\n";
    }
}

