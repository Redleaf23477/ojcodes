#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        tree[p].emplace_back(i);
    }
    vector<int> color(n);
    for (auto &x : color) { cin >> x; x--; }

    vector<int> tmp(n, -1);
    vector<vector<int>> color_tree(n);
    vector<int> in_time(n), out_time(n);
    int ts = 0;
    function<void(int)> dfs1 = [&](int u) {
        int c = color[u];
        if (tmp[c] != -1) {
            color_tree[tmp[c]].emplace_back(u);
        }
        int backup = tmp[c];
        tmp[c] = u;
        in_time[u] = ++ts;
        for (auto v : tree[u]) {
            dfs1(v);
        }
        out_time[u] = ++ts;
        tmp[c] = backup;
    };
    dfs1(0);

    LL ans = 1;
    function<LL(int)> dfs2 = [&](int u) {
        auto it = color_tree[u].begin();
        vector<LL> mx(3, 1);
        for (auto v : tree[u]) {
            LL sub = dfs2(v);
            while (it != color_tree[u].end() && out_time[*it] < in_time[v]) it++;
            if (it == color_tree[u].end() || out_time[*it] > out_time[v]) {
                sub += 1;
            }
            cerr << "sub " << u + 1 << "->" << v + 1 << " = " << sub << endl;
            mx.front() = sub;
            sort(mx.begin(), mx.end());
        }
        ans = max(ans, mx[1] * mx[2]);
        return mx[2];
    };
    dfs2(0);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

