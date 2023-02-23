#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int R, C; cin >> R >> C;
    vector<vector<int>> maze(R+2, vector<int>(C+2, 0));
    for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++) cin >> maze[r][c];
    int ps, pf, pr; cin >> ps >> pf >> pr;
    vector<int> dr {-1, 0, 1, 0, -1, 0, 1, 0};
    vector<int> dc {0, 1, 0, -1, 0, 1, 0, -1};
    for (int r = 1; r <= R; r++) for (int c = 1; c <= C; c++) {
        int ss = maze[r][c];
        bool good = false;
        for (int d = 0; d < 4; d++) {
            int ff = maze[r + dr[d]][c + dc[d]];
            int rr = maze[r + dr[d+1]][c + dc[d+1]];
            if (ps == ss && pf == ff && pr == rr) {
                good = true;
            }
        }
        if (good) cout << r - 1 << " " << c - 1 << "\n";
    }
}

