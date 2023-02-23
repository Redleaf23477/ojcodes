#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

LL solve() {
    int n; cin >> n;
    vector<int> A(n), B(n);
    for (auto &x : A) { cin >> x; x--; }
    for (auto &x : B) { cin >> x; x--; }

    int loop = 0;
    vector<bool> vis(n, false);
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        if (A[i] == B[i]) {
            loop++;
        }
        graph[A[i]].emplace_back(B[i]);
        graph[B[i]].emplace_back(A[i]);
    }

    int _v, _e;
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        _v++;
        for (auto v : graph[u]) {
            _e++;
            if (!vis[v]) {
                dfs(v);
            }
        }
    };

    int cycle = 0;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            _v = _e = 0;
            dfs(i);
            if (_v * 2 != _e) return 0;
            cycle++;
        }
    }
    cycle -= loop;


    LL ans = 1;
    while (cycle--) ans = ans * 2 % MOD;
    while (loop--) ans = ans * n % MOD;
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        cout << solve() << "\n";
    }
}

