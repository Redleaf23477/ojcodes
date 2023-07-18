#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL INF = 1e18;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<LL>> adj_mat(n, vector<LL>(n, INF));
    vector<vector<LL>> sp_cnt(n, vector<LL>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--, v--;
        adj_mat[u][v] = adj_mat[v][u] = w;
        sp_cnt[u][v] = sp_cnt[v][u] = 1;
    }
    vector<vector<LL>> APSP(adj_mat);

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (APSP[i][j] > APSP[i][k] + APSP[k][j]) {
                    APSP[i][j] = APSP[i][k] + APSP[k][j];
                    sp_cnt[i][j] = 0;
                }
                if (APSP[i][j] == APSP[i][k] + APSP[k][j]) {
                    sp_cnt[i][j] ++;
                }
            }
        }
    }

    int bye = 0;
    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (adj_mat[u][v] != INF) {
                if (adj_mat[u][v] > APSP[u][v]) bye++; 
                else if (sp_cnt[u][v] > 1) bye++;
            }
        }
    }
    cout << bye / 2 << "\n";

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



