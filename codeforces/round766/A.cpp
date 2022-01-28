#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool all_white(const vector<string> &maze) {
    for (auto row : maze) {
        for (auto c : row) {
            if (c == 'B') return false;
        }
    }
    return true;
}

bool on_same_rol_col(const vector<string> &maze, int r, int c) {
    for (auto x : maze[r]) {
        if (x == 'B') return true;
    }
    for (size_t i = 0; i < maze.size(); i++) {
        if (maze[i][c] == 'B') return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int R, C; cin >> R >> C;
        int r, c; cin >> r >> c; r--, c--;
        vector<string> maze(R);
        for (auto &x : maze) cin >> x;
        if (all_white(maze)) {
            cout << -1 << "\n";
        } else if (maze[r][c] == 'B') {
            cout << 0 << "\n";
        } else if (on_same_rol_col(maze, r, c)) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}

