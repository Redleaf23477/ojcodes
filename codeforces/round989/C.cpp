#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int R, C; cin >> R >> C;

    string dir_str = "UDLR?";
    const int UNKNOWN = 4;

    vector<vector<int>> arr(R, vector<int>(C, 0));
    for (auto &row : arr) {
        string s; cin >> s;
        for (int i = 0; i < C; i++) {
            row[i] = dir_str.find(s[i]);
        }
    }

    vector<vector<bool>> good(R, vector<bool>(C, false));

    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};
    vector<int> rev_dir = {1, 0, 3, 2};

    auto in_bound = [R, C](int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    };

    // step: for each ? pair, make 2-cycle if possible
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        if (arr[r][c] == UNKNOWN) {
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (in_bound(nr, nc) && arr[nr][nc] == UNKNOWN) {
                    arr[r][c] = d;
                    arr[nr][nc] = rev_dir[d];
                    good[r][c] = good[nr][nc] = true;
                    break;
                }
                if (in_bound(nr, nc) && arr[nr][nc] == rev_dir[d]) {
                    arr[r][c] = d;
                    good[r][c] = good[nr][nc] = true;
                    break;
                }
            }
        }
    }

    // step: find existing good
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    vector<vector<bool>> instk(R, vector<bool>(C, false));
    function<bool(int,int)> dfs = [&](int r, int c) {
        vis[r][c] = true;
        instk[r][c] = true;
        for (int d = 0; d < 4; d++) {
            if (arr[r][c] != UNKNOWN && arr[r][c] != d) continue;

            int nr = r + dr[d], nc = c + dc[d];
            if (!in_bound(nr, nc)) continue;
            if (instk[nr][nc] || good[nr][nc]) {
                good[r][c] = true; break;
            }
            if (!vis[nr][nc] && dfs(nr, nc)) {
                good[r][c] = true; break;
            }
        }
        instk[r][c] = false;
        return good[r][c];
    };
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        if (!vis[r][c]) dfs(r, c);
    }

    // step: for remaining ? check neighbor
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        if (arr[r][c] == UNKNOWN) {
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (in_bound(nr, nc) && good[nr][nc]) {
                    good[r][c] = true;
                    arr[r][c] = d;
                    break;
                }
            }
        }
    }

    int ans = 0;
    for (auto &row : good) for (auto cell : row) ans += cell;
    cout << ans << "\n";

    /*
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        cerr << arr[r][c] << " \n"[c == C - 1];
    }
    */
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

