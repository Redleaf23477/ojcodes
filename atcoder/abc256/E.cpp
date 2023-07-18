#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> hate(n);
    for (auto &x : hate) { cin >> x; x--; }
    vector<LL> frust(n);
    for (auto &x : frust) cin >> x;

    LL ans = 0;
    vector<bool> vis(n, false), instk(n, false);
    vector<int> stk;
    function<LL(int)> dfs = [&](int u) {
        vis[u] = instk[u] = true;
        stk.emplace_back(u);
        int v = hate[u];
        LL ans = 0;
        if (instk[v]) {
            ans = frust[v];
            for (int i = stk.size() - 1; stk[i] != v; i--) {
                ans = min(ans, frust[stk[i]]);
            }
        } else if (!vis[v]) {
            ans = dfs(v);
        }
        instk[u] = false;
        stk.pop_back();
        return ans;
    };
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            ans += dfs(i);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



