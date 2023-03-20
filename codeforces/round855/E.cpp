#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    string s1, s2; cin >> s1 >> s2;
    vector<vector<int>> cc;
    vector<bool> vis(n, false);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        cc.back().emplace_back(u);
        for (auto d : {k, k+1, -k, -k-1}) {
            int v = u + d;
            if (0 <= v && v < n && !vis[v]) {
                dfs(v);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            cc.emplace_back(vector<int>());
            dfs(i);
        }
    }

    for (auto &c : cc) {
        vector<int> cnt(26, 0);
        for (auto x : c) {
            cnt[s1[x] - 'a']++;
            cnt[s2[x] - 'a']--;
        }
        for (auto x : cnt) {
            if (x != 0) {
                cout << "NO\n"; return;
            }
        }
    }
    cout << "YES\n"; 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



