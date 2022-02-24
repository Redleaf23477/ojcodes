#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;
constexpr int N = 20;
 
int graph[N][N];
LL dp[(1<<N)][N];
 
int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u][v] += 1;
    }
    dp[1][0] = 1;
    for (int s = 1; s < (1<<n); s += 2) {   // s % 2 == 0 must be invalid
        for (int u = 1; u < n; u++) {
            if ((s >> u) & 1) {
                for (int v = 0; v < n; v++) {
                    if (((s >> v) & 1) && graph[v][u] > 0) {
                        dp[s][u] = (dp[s][u] + dp[s^(1<<u)][v] * graph[v][u]) % MOD;
                    }
                }
            }
        }
    }
    cout << dp[(1<<n)-1][n-1] << "\n";
}
