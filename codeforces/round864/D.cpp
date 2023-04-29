#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
// using P = pair<int,int>; // (subtree size, vertex index)
                         
struct P {
    int first, second;
    P(int a, int b) : first(a), second(b) {};
};

bool operator< (P const &lhs, P const &rhs) {
    if (lhs.first != rhs.first) return lhs.first < rhs.first;
    else return lhs.second > rhs.second;
}

void solve() {
    int n, q; cin >> n >> q;
    vector<LL> val(n);
    for (auto &x : val) cin >> x;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        tree[u].emplace_back(v);
        tree[v].emplace_back(u);
    }

    vector<LL> val_sum(n, 0);
    vector<set<P>> sorted_tree(n);
    vector<int> pa(n), sz(n);
    function<void(int,int)> dfs = [&](int u, int p) {
        pa[u] = p;
        sz[u] = 1;
        val_sum[u] += val[u];
        for (auto v : tree[u]) {
            if (v == p) continue;
            dfs(v, u);
            sorted_tree[u].insert(P(sz[v], v));
            sz[u] += sz[v];
            val_sum[u] += val_sum[v];
        }
    };
    dfs(0, 0);

    while (q--) {
        int op; cin >> op;
        LL x; cin >> x;
        if (op == 1) {
            cout << val_sum[x-1] << "\n";
        } else {
            int u = x - 1, p = pa[u];
            /*
            cerr << "tree[" << u+1 << "] -> ";
            for (auto [sz, v] : sorted_tree[u]) {
                cerr << "(" << sz << ", " << v+1 << ") ";
            }
            cerr << endl;
            */
            if (sorted_tree[u].size() == 0) continue;
            auto [_, v] = *sorted_tree[u].rbegin();
            /*
            cerr << "v = " << v+1 << endl;
            */
            // remove u from p
            sorted_tree[p].erase(sorted_tree[p].find(P(sz[u], u)));
            // remove v from u
            sorted_tree[u].erase(sorted_tree[u].find(P(sz[v], v)));
            // add u to v
            sz[u] -= sz[v];
            val_sum[u] -= val_sum[v];
            pa[u] = v;
            sorted_tree[v].insert(P(sz[u], u));
            sz[v] += sz[u];
            val_sum[v] += val_sum[u];
            // add v to p
            pa[v] = p;
            sorted_tree[p].insert(P(sz[v], v));

            /*
            for (int i = 0; i < n; i++) {
                cerr << i + 1 << " -> " << val_sum[i] << endl;
            }
            */
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



