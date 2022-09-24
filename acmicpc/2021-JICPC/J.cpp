#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int R, C; cin >> R >> C;
    vector<vector<int>> arr(R, vector<int>(C));
    for (auto &row : arr) for (auto &col : row) cin >> col;

    // -1: unvisited, 0: no_mark, 1: marked
    vector<vector<int>> mark(R, vector<int>(C, -1));

    vector<int> dr {-1, 1, 0, 0}, dc {0, 0, 1, -1};
    auto legal = [R, C](int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    };

    vector<tuple<int,int>> stacktrace;
    function<void(int,int,int,vector<tuple<int,int>>&)> dfs = [&](int r, int c, int color, vector<tuple<int,int>> &mem) {
        mark[r][c] = color;
        stacktrace.emplace_back(r, c);
        if (color == 1) mem.emplace_back(r, c);

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (legal(nr, nc) && mark[nr][nc] == -1 && arr[r][c] == arr[nr][nc]) {
                dfs(nr, nc, 1 - color, mem);
            }
        }
    };

    auto do_mark = [&](int r, int c) {
        // case 1: mark (r, c)
        stacktrace.clear();
        vector<tuple<int,int>> m1;
        dfs(r, c, 1, m1);
        for (auto [r, c] : stacktrace) {
            mark[r][c] = -1;
        }

        // case 2: no mark (r, c)
        stacktrace.clear();
        vector<tuple<int,int>> m2;
        dfs(r, c, 0, m2);

        if (m1.size() < m2.size()) {
            // recolor using m1
            for (auto [r, c] : stacktrace) {
                mark[r][c] = 0;
            }
            for (auto [r, c] : m1) {
                mark[r][c] = 1;
            }
        }
    };

    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        if (mark[r][c] == -1) {
            do_mark(r, c);
        }
    }

    // print answer
    vector<tuple<int,int,int>> ans;
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        if (mark[r][c] == 1) ans.emplace_back(r + 1, c + 1, 1);
    }
    if (ans.size() == 0) {
        cout << 0 << " " << 0 << "\n";
    } else {
        cout << 1 << " " << ans.size() << "\n";
        for (auto [r, c, m] : ans) {
            cout << r << " " << c << " " << m << "\n";
        }
    }
}

