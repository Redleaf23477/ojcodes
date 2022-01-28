#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> pa(n), perm(n);
    vector<vector<int>> tree(n);
    for (int i = 0; i < n; i++) {
        cin >> pa[i]; pa[i]--;
        if (pa[i] != i) tree[pa[i]].emplace_back(i);
    }
    for (auto &x : perm) {
        cin >> x; x--;
    }

    vector<int> dist(n, 0), wei(n, 0);
    set<int> cand;
    // find root
    for (int i = 0; i < n; i++) {
        if (pa[i] == i) {
            cand.insert(i); break;
        }
    }
    int len = 0;
    for (auto p : perm) {
        if (cand.count(p) == 0) {
            cout << "-1\n"; return;
        }
        dist[p] = len, wei[p] = dist[p] - dist[pa[p]];
        len++;
        cand.erase(p);
        for (auto v : tree[p]) {
            cand.insert(v);
        }
    }
    for (auto w : wei) {
        cout << w << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

