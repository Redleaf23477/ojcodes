#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int R, C; cin >> R >> C;
    vector<vector<char>> maze(R, vector<char>(C));
    for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
        cin >> maze[r][c];
    }
    int sr, sc; cin >> sr >> sc; sr--, sc--;
    int er, ec; cin >> er >> ec; er--, ec--;

    // direction: up, right, down, left
    const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;
    vector<int> dr {-1, 0, 1, 0};
    vector<int> dc {0, 1, 0, -1};

    auto enc = [&](int r, int c, int rot) {
        // idx = rot * (R*C) + r * C + c
        return rot * (R * C) + r * C + c;
    };
    auto dec = [&](int idx) {
        // idx = rot * (R*C) + r * C + c
        int rot = idx / (R * C);
        idx %= R * C;
        int r = idx / C;
        int c = idx % C;
        return make_tuple(r, c, rot);
    };
    auto check_door = [&](char block, int dir) {
        if (block == '+') {
            return true;
        } else if (block == '-') {
            return dir == LEFT || dir == RIGHT; 
        } else if (block == '|') {
            return dir == UP || dir == DOWN;
        } else if (block == '^') {
            return dir == UP;
        } else if (block == '>') {
            return dir == RIGHT;
        } else if (block == '<') {
            return dir == LEFT; 
        } else if (block == 'v') {
            return dir == DOWN;
        } else if (block == 'L') {
            return dir != LEFT; 
        } else if (block == 'R') {
            return dir != RIGHT;
        } else if (block == 'U') {
            return dir != UP;
        } else if (block == 'D') {
            return dir != DOWN;
        } else if (block == '*') {
            return false;
        } else {
            assert(false && "unreachable");
            return false;
        }
    };
    auto reachable = [&](int r, int c, int rot, int dir) {
        int nr = r + dr[dir], nc = c + dc[dir];
        // check bound
        if (!(0 <= nr && nr < R && 0 <= nc && nc < C)) {
            return false;
        }
        // check door (r, c) --> (nr, nc)
        if (!check_door(maze[r][c], (dir + rot * 3) % 4)) {
            return false;
        }
        // check door (nr, nc) --> (r, c)
        if (!check_door(maze[nr][nc], (dir + 2 + rot * 3) % 4)) {
            return false;
        }
        // yeah
        return true;
    };
    auto dijk = [&]() {
        using Node = tuple<int,int>; // (dist, idx)
        const int INF = 5 * R * C;

        vector<int> dist(4 * R * C, INF);
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.emplace(0, enc(sr, sc, 0));
        dist[enc(sr, sc, 0)] = 0;

        while (!pq.empty()) {
            auto [len, idx] = pq.top(); pq.pop();
            auto [r, c, rot] = dec(idx);

            // found answer
            if (r == er && c == ec) {
                return len; 
            }

            // push button
            int nidx_button = enc(r, c, (rot + 1) % 4);
            if (dist[nidx_button] > len + 1) {
                dist[nidx_button] = len + 1;
                pq.emplace(len + 1, nidx_button);
            }

            // go to neighbor
            for (int d = 0; d < 4; d++) {
                if (reachable(r, c, rot, d)) {
                    int nr = r + dr[d], nc = c + dc[d];
                    int nidx_go = enc(nr, nc, rot);
                    if (dist[nidx_go] > len + 1) {
                        dist[nidx_go] = len + 1;
                        pq.emplace(len + 1, nidx_go);
                    }
                }
            }
        }

        return -1;
    };

    cout << dijk() << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



