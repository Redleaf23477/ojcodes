#include <bits/stdc++.h>
using namespace std;
using LL = long long int;


void solve() {
    int R, C; cin >> R >> C;
    vector<string> maze(R);
    for (auto &row : maze) cin >> row;

    auto legal = [&](int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C && maze[r][c] != '#';
    };

    auto bfs = [&](int r, int c) {
        using T = tuple<int,int>;
        vector<int> dr {-1, 1, 0, 0}, dc {0, 0, 1, -1};
        vector<vector<int>> sp(R, vector<int>(C, -1));
        sp[r][c] = 0;
        queue<T> q; q.emplace(r, c);
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (legal(nr, nc) && sp[nr][nc] == -1) {
                    sp[nr][nc] = sp[r][c] + 1;
                    q.emplace(nr, nc);
                }
            }
        }
        return sp;
    };

    int r1, c1;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        if (maze[r][c] == 'H') r1 = r, c1 = c;
    }
    vector<vector<int>> sp = bfs(r1, c1);

    int k; cin >> k;
    int ans = -1;
    for (int i = 0; i < k; i++) {
        int r, c; cin >> r >> c; r--, c--;
        if (maze[r][c] == '#') continue;
        if (sp[r][c] != -1 && sp[r][c] <= i) {
            if (ans == -1) ans = i;
            else ans = min(ans, i);
        }
    }

    if (ans == -1) cout << "NO\n";
    else cout << "YES " << ans << "\n";

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

