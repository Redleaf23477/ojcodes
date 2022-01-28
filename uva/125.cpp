#include <bits/stdc++.h>
using namespace std;

using LL = long long int;

const int N = 30;
LL dp[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, caseN = 0; 
    while (cin >> n) {
        cout << "matrix for city " << caseN++ << endl;
        memset(dp, 0, sizeof(dp));
        int m = 0;
        while (n--) {
            int u, v; cin >> u >> v;
            m = max({m, u, v});
            dp[u][v] += 1;
        }
        m += 1;
        // floyd warshall two times
        for (int k = 0; k < m; k++) 
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    // loop propagate
                    if (dp[i][k] > 0 && dp[k][j] == -1) {
                        dp[i][j] = -1;
                    }
                    if (dp[i][k] == -1 && dp[k][j] > 0) {
                        dp[i][j] = -1;
                    }
                    if (dp[i][k] == -1 && dp[k][j] == -1) {
                        dp[i][j] = -1;
                    }
                    // calculate path
                    if (dp[i][j] != -1) {
                        dp[i][j] = dp[i][j] + dp[i][k] * dp[k][j];
                    }
                }
                // mark loop
                if (dp[i][i] > 0) dp[i][i] = -1;
            }
        for (int k = 0; k < m; k++)
            for (int i = 0; i < m; i++) 
                for (int j = 0; j < m; j++) {
                    // loop propagate
                    if (dp[i][k] > 0 && dp[k][j] == -1) {
                        dp[i][j] = -1;
                    }
                    if (dp[i][k] == -1 && dp[k][j] > 0) {
                        dp[i][j] = -1;
                    }
                    if (dp[i][k] == -1 && dp[k][j] == -1) {
                        dp[i][j] = -1;
                    }
                }

        // output
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                cout << dp[i][j] << " \n"[j+1==m];
            }
        }
    }
}

