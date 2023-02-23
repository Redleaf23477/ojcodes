#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct DisjointSet {
    int n;
    vector<int> pa;
    DisjointSet(int _n) : n(_n), pa(n) {
        iota(pa.begin(), pa.end(), 0);
    }
    int findrt(int x) {
        if (x == pa[x]) return x;
        return pa[x] = findrt(pa[x]);
    }
    bool same(int x, int y) {
        return findrt(x) == findrt(y);
    }
    void uni(int x, int y) {
        x = findrt(x), y = findrt(y);
        if (x == y) return;
        pa[x] = y;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<int> D(n), Dsum(n);
    for (int i = 0; i < n; i++) {
        cin >> D[i];
        Dsum[i] = D[i];
        if (D[i] == 0) {
            cout << -1 << "\n"; return;
        }
    }
    vector<list<int>> demand_list(n);
    for (int i = 0; i < n; i++) demand_list[i].emplace_back(i);
    auto decrease_demand = [&](int u) {
        int f = demand_list[u].front();
        Dsum[u]--;
        if (--D[f] == 0) demand_list[u].pop_front();
        return f;
    };

    DisjointSet dsu(n);
    auto merge = [&](int u, int v) {
        int u2 = decrease_demand(u);
        int v2 = decrease_demand(v);
        Dsum[v] += Dsum[u];
        Dsum[u] = 0;
        demand_list[v].splice(demand_list[v].end(), demand_list[u]);
        dsu.uni(u, v);
        return make_pair(u2, v2);

        /*
        cerr << "merge: " << u << " " << v << endl;
        cerr << "D: ";
        for (auto d : D) cerr << d << " ";
        cerr << endl;
        cerr << "Dsum: ";
        for (auto s : Dsum) cerr << s << " ";
        cerr << endl;
        */
    };

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        if (dsu.same(u, v)) {
            cout << -1 << "\n"; return;
        }
        u = dsu.findrt(u);
        v = dsu.findrt(v);
        merge(u, v);
    }

    vector<int> leaf, internal;
    for (int i = 0; i < n; i++) {
        if (Dsum[i] == 0) continue;
        else if (Dsum[i] == 1) leaf.emplace_back(i);
        else internal.emplace_back(i);
    }

    vector<pair<int,int>> ans;
    for (int e = m + 1; e <= n-1; e++) {
        if (internal.size() >= 2) {
            int u = internal.back(); internal.pop_back();
            int v = internal.back(); internal.pop_back();
            auto p = merge(u, v);
            ans.emplace_back(p);
            if (Dsum[v] >= 2) internal.emplace_back(v);
            else if (Dsum[v] == 1) leaf.emplace_back(v);
            else assert(false && "unreachable");
        } else if (internal.size() == 1) {
            if (leaf.size() == 0) {
                cout << -1 << "\n"; return;
            }
            int u = leaf.back(); leaf.pop_back();
            int v = internal.back(); internal.pop_back();
            auto p = merge(u, v);
            ans.emplace_back(p);
            if (Dsum[v] >= 2) internal.emplace_back(v);
            else if (Dsum[v] == 1) leaf.emplace_back(v);
            else assert(false && "unreachable");
        } else {
            if (leaf.size() != 2) {
                cout << -1 << "\n"; return;
            } else {
                int u = leaf.back(); leaf.pop_back();
                int v = leaf.back(); leaf.pop_back();
                auto p = merge(u, v);
                ans.emplace_back(p);
            }
        }
    }

    if (!leaf.empty() || !internal.empty()) {
        cout << -1 << "\n"; return;
    }

    // print answer
    for (auto [u, v] : ans) {
        cout << u + 1 << " " << v + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}

