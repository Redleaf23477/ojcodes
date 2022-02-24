#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<string> maze(n); 
    for (auto &r : maze) cin >> r;
    vector<int> dr {-1, 1, 0, 0}, dc {0, 0, 1, -1};
    auto legal = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m;
    };
    function<void(int,int)> dfs = [&](int r, int c) {
        maze[r][c] = 'x';
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (legal(nr, nc) && maze[nr][nc] == '.') {
                dfs(nr, nc);
            }
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (maze[i][j] == '.') {
            ans += 1;
            dfs(i, j);
        }
    }
    cout << ans << "\n";
}

