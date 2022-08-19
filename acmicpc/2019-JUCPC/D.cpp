#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    vector<string> maze {
        "............",
        "............",
        "..*......*..",
        "............",
        "............",
        ".....##.....",
        ".....##.....",
        "............",
        ".##......##.",
        ".#*......*#.",
        "............",
        "............"
    };
    assert(maze.size() == 12);
    for (auto &row : maze) assert(row.size() == 12);

    // bfs
    using P = tuple<int,int>;
    queue<P> q;
    for (int i = 0; i < 12; i++) for (int j = 0; j < 12; j++) {
        if (maze[i][j] == '*') q.emplace(i, j);
    }
    auto legal = [](int r, int c) {
        return 0 <= r && r < 12 && 0 <= c && c < 12;
    };
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        int nr, nc;
        // go up
        nr = r - 1, nc = c;
        if (legal(nr, nc) && maze[nr][nc] == '.') {
            maze[nr][nc] = 'D';
            q.emplace(nr, nc);
        }
        // go down
        nr = r + 1, nc = c;
        if (legal(nr, nc) && maze[nr][nc] == '.') {
            maze[nr][nc] = 'U';
            q.emplace(nr, nc);
        }
        // go left
        nr = r, nc = c - 1;
        if (legal(nr, nc) && maze[nr][nc] == '.') {
            maze[nr][nc] = 'R';
            q.emplace(nr, nc);
        }
        // go right
        nr = r, nc = c + 1;
        if (legal(nr, nc) && maze[nr][nc] == '.') {
            maze[nr][nc] = 'L';
            q.emplace(nr, nc);
        }
    }


    int Q; cin >> Q;
    while (Q--) {
        int r, c; cin >> r >> c; r--, c--;
        string ans;

        while (maze[r][c] != '*') {
            ans.push_back(maze[r][c]);
            char d = maze[r][c];
            if (d == 'U') r--;
            else if (d == 'D') r++;
            else if (d == 'L') c--;
            else c++;
        }


        cout << ans.size() << "\n" << ans << "\n";
    }
}

