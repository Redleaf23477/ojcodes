#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<vector<int>> arr(2*n, vector<int>(2*n, 0));
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            int x; cin >> x;
            arr[i][j] = arr[j][i] = x;
        }
    }

    /*
    cerr << "debug" << endl;
    for (int i = 0; i < 2 * n; i++) for (int j = 0; j < 2 * n; j++) {
        cerr<< arr[i][j] << " \n"[j == 2*n-1];
    }
    cerr << endl;
    */

    int ans = 0;
    function<void(int,int,int)> dfs = [&](int mask, int N, int res) {
        // recursion end
        if (mask == (1 << N) - 1) {
            ans = max(ans, res);
            return;
        }

        // find first unmatched
        int u = -1;
        for (int i = 0; i < N && u == -1; i++) {
            if (((mask >> i) & 1) == 0) u = i;
        }
        // find the one that should be paired to u
        for (int i = u+1; i < N; i++) {
            if (((mask >> i) & 1) == 0) {
                int v = i;
                dfs(mask | (1 << u) | (1 << v), N, res ^ arr[u][v]);
            }
        }
    };

    dfs(0, 2*n, 0);
    cout << ans << "\n";
}

