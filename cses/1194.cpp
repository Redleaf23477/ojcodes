#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using P = tuple<int,int>;

const vector<int> dr {-1, 1, 0, 0}, dc {0, 0, -1, 1};
const string dir("UDLR");
const int INF = 48763;

int n, m;

bool legal(int r, int c) {
    return 0 <= r && r < n && 0 <= c && c < m;
}

void bfs1(vector<string> &maze, vector<vector<int>> &monster_path) {
    queue<P> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'M') {
                q.emplace(i, j);
                monster_path[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (legal(nr, nc) && maze[nr][nc] != '#' && monster_path[nr][nc] == INF) {
                monster_path[nr][nc] = monster_path[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }
}

void bfs2(vector<string> &maze, vector<vector<int>> &monster_path) {
    queue<P> q;
    vector<vector<int>> my_dist(n, vector<int>(m, INF));
    vector<string> my_path(n, string(m, 'X'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (maze[i][j] == 'A') {
                q.emplace(i, j);
                my_dist[i][j] = 0;
            }
        }
    }
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        int d = my_dist[r][c];
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i], nd = d + 1;
            if (legal(nr, nc) && maze[nr][nc] != '#' && my_dist[nr][nc] == INF && monster_path[nr][nc] > nd) {
                my_dist[nr][nc] = nd;
                my_path[nr][nc] = dir[i];
                q.emplace(nr, nc);
            }
        }
    }
    // print ans
    function<void(int,int)> print = [&](int r, int c) {
        cout << "YES\n";
        string ans;
        while (my_dist[r][c] != 0) {
            if (my_path[r][c] == 'U') ans.push_back('U'), r += 1;
            else if (my_path[r][c] == 'D') ans.push_back('D'), r -= 1;
            else if (my_path[r][c] == 'L') ans.push_back('L'), c += 1;
            else ans.push_back('R'), c -= 1;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n" << ans << "\n";
    };
    for (int i = 0; i < n; i++) {
        if (my_dist[i][0] != INF) {
            print(i, 0); return;
        }
        if (my_dist[i][m-1] != INF) {
            print(i, m-1); return;
        }
    }
    for (int i = 0; i < m; i++) {
        if (my_dist[0][i] != INF) {
            print(0, i); return;
        }
        if (my_dist[n-1][i] != INF) {
            print(n-1, i); return;
        }
    }
    // no sol
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    cin >> n >> m;
    vector<string> maze(n);
    for (auto &r : maze) cin >> r;
    
    vector<vector<int>> monster_path(n, vector<int>(m, INF));
    bfs1(maze, monster_path);

    bfs2(maze, monster_path);
}

