#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<pair<LL, int>>> tree(n);
    for (int i = 1; i < n; i++) {
        int pa; cin >> pa; pa--;
        LL w; cin >> w;
        tree[pa].emplace_back(w, i);
    }
    vector<bool> sad(n, false);
    vector<LL> pref_sum {0}, pref_min {0};
    function<void(int)> dfs = [&](int u) {
        LL max_path = pref_sum.back() - pref_min.back();
        if (max_path > arr[u]) {
            sad[u] = true;
        }
        for (auto [w, v] : tree[u]) {
            pref_sum.emplace_back(pref_sum.back() + w);
            pref_min.emplace_back(min(pref_min.back(), pref_sum.back()));
            dfs(v);
            pref_sum.pop_back();
            pref_min.pop_back();
        }
    };
    dfs(0);
    function<int(int,bool)> dfs2 = [&](int u, bool bye) {
        int ans = 0;
        if (sad[u]) bye = true;
        if (bye) ans++;
        for (auto [w, v] : tree[u]) {
            ans += dfs2(v, bye);
        }
        return ans;
    };
    cout << dfs2(0, false) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



