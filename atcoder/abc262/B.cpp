#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, M; cin >> N >> M;
    vector<vector<bool>> graph(N, vector<bool>(N, false));
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v; u--, v--;
        graph[u][v] = graph[v][u] = true;
    }
    int ans = 0;
    for (int a = 0; a < N; a++) {
        for (int b = a + 1; b < N; b++) {
            for (int c = b + 1; c < N; c++) {
                if (graph[a][b] && graph[b][c] && graph[c][a]) {
                    ans++;
                }
            }
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



