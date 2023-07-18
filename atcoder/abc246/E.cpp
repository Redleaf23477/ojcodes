#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int dijk_with_deque(pair<int,int> source, pair<int,int> dest, vector<vector<char>> const &board) {
    int N = board.size();
    int INF = N * N;
    vector<int> dr {-1, -1, 1, 1}, dc {-1, 1, -1, 1};

    vector dist(N, vector<vector<int>>(N, vector<int>(4, INF)));
    vector vis(N, vector<vector<bool>>(N, vector<bool>(4, false)));
    deque<tuple<int,int,int>> DQ;
    for (int dir = 0; dir < 4; dir++) {
        dist[source.first][source.second][dir] = 1;
        DQ.emplace_back(source.first, source.second, dir);  // (r, c, prev_dir)
    }
                                                     
    auto relax_four_directions = [&](int r, int c, int prv_dir) {
        // move foward
        int nr = r + dr[prv_dir], nc = c + dc[prv_dir];
        if (0 <= nr && nr < N && 0 <= nc && nc < N) {
            if (board[nr][nc] == '.' && !vis[nr][nc][prv_dir]) {
                if (dist[r][c][prv_dir] < dist[nr][nc][prv_dir]) {
                    dist[nr][nc][prv_dir] = dist[r][c][prv_dir];
                    DQ.emplace_front(nr, nc, prv_dir);
                }
            }
        }
        // change direction
        for (int dir = 0; dir < 4; dir++) {
            if (dir != prv_dir && !vis[r][c][dir]) {
                if (dist[r][c][prv_dir] + 1 < dist[r][c][dir]) {
                    dist[r][c][dir] = dist[r][c][prv_dir] + 1;
                    DQ.emplace_back(r, c, dir);
                }
            }
        }
    };

    while (!DQ.empty()) {
        auto [r, c, prv_dir] = DQ.front(); DQ.pop_front();
        if (vis[r][c][prv_dir]) continue;
        if (r == dest.first && c == dest.second) {
            return dist[r][c][prv_dir];
        }
        vis[r][c][prv_dir] = true;
        relax_four_directions(r, c, prv_dir);
    }
    return -1;
}

void solve() {
    int N; cin >> N;
    pair<int,int> source, dest; 
    cin >> source.first >> source.second;
    cin >> dest.first >> dest.second;
    source.first--, source.second--;
    dest.first--, dest.second--;
    vector<vector<char>> board(N, vector<char>(N));
    for (auto &row : board) {
        for (auto &elem : row) {
            cin >> elem;
        }
    }

    cout << dijk_with_deque(source, dest, board) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



