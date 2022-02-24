#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using P = tuple<int,int>;

P find_pos(vector<string> &maze, char ch) {
    for (size_t i = 0; i < maze.size(); i++) {
        for (size_t j = 0; j < maze[i].size(); j++) {
            if (maze[i][j] == ch) return P(i, j);
        }
    }
    return P(-1, -1);
}


bool bfs(vector<string> &maze, const P START) {
    vector<int> dr {-1, 1, 0, 0}, dc {0, 0, -1, 1};
    string dir("UDLR");
    auto legal = [&](int r, int c) {
        return 0 <= r && r < (int)maze.size() && 0 <= c && c < (int)maze[0].size();
    };
    auto print_sol = [&](int r, int c) {
        string str; 
        while (P(r, c) != START) {
            char d = maze[r][c];
            str.push_back(d);
            if (d == 'U') r += 1;
            else if (d == 'D') r -= 1;
            else if (d == 'L') c += 1;
            else c -= 1;
        }
        reverse(str.begin(), str.end());
        cout << "YES\n" << str.size() << "\n" << str << "\n";
    };
    // bfs
    queue<P> q({START});
    while (!q.empty()) {
        P f = q.front(); q.pop();
        auto [r, c] = f;
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (!legal(nr, nc)) continue;
            if (maze[nr][nc] == '.') {
                maze[nr][nc] = dir[i];
                q.emplace(nr, nc);
            } else if (maze[nr][nc] == 'B') {
                maze[nr][nc] = dir[i];
                print_sol(nr, nc);
                return true;
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<string> maze(n);
    for (auto &r : maze) cin >> r;
    P pos_start = find_pos(maze, 'A');
    if (!bfs(maze, pos_start)) {
        cout << "NO\n";
    }
}

