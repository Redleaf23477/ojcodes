#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> pa(n);
    vector<set<int>> s(n);

    iota(pa.begin(), pa.end(), 0);
    for (int i = 0; i < n; i++) s[i].insert(i + 1);

    function<int(int)> findpa = [&](int x) {
        if (pa[x] == x) return x;
        else return pa[x] = findpa(pa[x]);
    };

    while (q--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int u, v; cin >> u >> v; u--, v--;
            findpa(u);
            findpa(v);
            if (pa[u] == pa[v]) continue;

            if (s[pa[u]].size() > s[pa[v]].size()) {
                swap(u, v);
            }
            // merge u into v
            s[pa[v]].insert(s[pa[u]].begin(), s[pa[u]].end());
            s[pa[u]].clear();
            pa[pa[u]] = pa[v];
        } else {
            int v, k; cin >> v >> k; v--;
            findpa(v);
            if (k > s[pa[v]].size()) {
                cout << -1 << "\n";
            } else {
                auto it = s[pa[v]].rbegin();
                for (int i = 1; i < k; i++) it++;
                cout << *it << "\n";
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

