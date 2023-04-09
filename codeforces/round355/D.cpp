#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;
const int INF = 600 * 90000;

void solve() {
    int n, m, p; cin >> n >> m >> p;
    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<P>> pos(p);
    for (int r = 0; r < n; r++) for (int c = 0; c < m; c++) {
        cin >> maze[r][c]; maze[r][c]--;
        pos[maze[r][c]].emplace_back(r, c);
    }
    vector<vector<int>> dist(n, vector<int>(m, INF));
    for (auto [r, c] : pos[0]) {
        dist[r][c] = r + c;
    }

    auto legal = [&](int r, int c) {
        return 0 <= r && r < n && 0 <= c && c < m; 
    };
    vector<int> dr {-1, 1, 0, 0}, dc {0, 0, 1, -1};
    auto bfs = [&](int now) {
        sort(pos[now-1].begin(), pos[now-1].end(), [&](P const &lhs, P const &rhs) {
            return dist[lhs.first][lhs.second] < dist[rhs.first][rhs.second];
        });
        vector<vector<int>> vis(n, vector<int>(m, INF));
        auto it = pos[now-1].begin();
        queue<P> Q;
        while (!Q.empty() || it != pos[now-1].end()) {
            while (it != pos[now-1].end()) {
                if (Q.empty() || vis[Q.front().first][Q.front().second] + 1 >= dist[it->first][it->second]) {
                    if (vis[it->first][it->second] == INF) {
                        Q.emplace(*it); 
                        vis[it->first][it->second] = dist[it->first][it->second];
                    }
                    it++;
                } else {
                    break;
                }
            }
            auto [r, c] = Q.front(); Q.pop();
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (legal(nr, nc) && vis[nr][nc] == INF) {
                    vis[nr][nc] = vis[r][c] + 1;
                    if (maze[nr][nc] == now) dist[nr][nc] = vis[nr][nc];
                    Q.emplace(nr, nc);
                }
            }
        }
    };
    auto pairwise_iterate = [&](int now) {
        for (auto [r, c] : pos[now-1]) for (auto [nr, nc] : pos[now]) {
            dist[nr][nc] = min(dist[nr][nc], dist[r][c] + abs(nr - r) + abs(nc - c));
        }
    };
    for (int i = 1; i < p; i++) {
        if (pos[i-1].size() * pos[i].size() >= n * m) {
            bfs(i);
        } else {
            pairwise_iterate(i);
        }
    }
    auto [er, ec] = pos.back().back();
    cout << dist[er][ec] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



