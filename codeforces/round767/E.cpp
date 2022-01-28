#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
    }

    int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};

    vector<vector<int>> vis(n, vector<int>(n, 0));
    int sum = 0;
    for (int r = 1; r < n; r++) for (int c = 0; c < n; c++) {
        if (vis[r-1][c] == 0) {
            sum ^= arr[r][c];
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (0 <= nr && nr < n && 0 <= nc && nc < n) {
                    vis[nr][nc] ^= 1;
                }
            }
        }
    }

    cout << sum << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

