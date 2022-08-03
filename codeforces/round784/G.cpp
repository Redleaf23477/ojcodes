#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int R, C; cin >> R >> C;
    vector<string> maze(R);
    for (auto &x : maze) cin >> x;


    auto place = [&](int r, int c, int cnt) {
        for (int i = 1; i <= cnt; i++) {
            maze[r-i][c] = '*';
        }
    };

    for (int col = 0; col < C; col++) {
        int cnt = 0;
        for (int r = 0; r < R; r++) {
            if (maze[r][col] == '*') cnt++, maze[r][col] = '.';
            else if (maze[r][col] == 'o') place(r, col, cnt), cnt = 0;
        }
        place(R, col, cnt);
    }

    for (auto &x : maze) {
        cout << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

