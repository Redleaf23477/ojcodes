#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 998244353;

LL fastpw(LL x, LL p) {
    if (x == 0) return 0;
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p /= 2;
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> P(n), Q(n);
    for (auto &x : P) {
        cin >> x; x--;
    }
    for (auto &x : Q) {
        cin >> x; x--;
    }
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        graph[P[i]].emplace_back(Q[i]);
    }

    // F(n): # edge cover on a linked list = FIB(n-1)
    // G(n): # edge cover on a linked list where the leftmost vertex is already covered
    // H(n): # edge cover on a linked list where the leftmost/rightmost vertex is already covered
    // C(n): # edge cover on a cycle
    vector<LL> F(n+1, 0), G(n+1, 0), H(n+1, 0), C(n+1, 0); 
    F[0] = 0, F[1] = 0, F[2] = 1;
    for (int i = 3; i <= n; i++) F[i] = (F[i-1] + F[i-2]) % MOD;
    G[0] = 0;
    for (int i = 1; i <= n; i++) G[i] = (F[i] + F[i-1]) % MOD;
    H[0] = 0, H[1] = 1;
    for (int i = 2; i <= n; i++) H[i] = (F[i-2] + 2 * G[i] - H[i-2] + MOD) % MOD;
    for (int i = 0; i <= n; i++) C[i] = (F[i] + H[i]) % MOD;

    vector<int> vis(n, false);
    function<int(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v : graph[u]) {
            if (vis[v]) return 1;
            else return 1 + dfs(v);
        }
        return -1; // unreachable
    };

    LL ans = 1;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        int cc_size = dfs(i);
        ans = ans * C[cc_size] % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}

