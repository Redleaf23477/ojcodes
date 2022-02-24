#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
 
constexpr int N = 48, M = 7;
constexpr int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
 
int cmd[N];
int H[N+1], V[N+1], Q[N+1];
bool vis[M][M], bfs_vis[M][M];
pair<int,int> q[N];
 
inline bool legal(int r, int c) {
    return 0 <= r && r < M && 0 <= c && c < M;
}

inline bool possible(int n, int sr, int sc) {
    memcpy(bfs_vis, vis, sizeof(vis));
    bfs_vis[sr][sc] = true;
    int cnt = 0;
    int f = 0, b = 0;
    if (bfs_vis[M-1][0] == false) {
        q[b++] = make_pair(M-1, 0); bfs_vis[M-1][0] = true;
    }
    while (f < b) {
        auto [r, c] = q[f++];
        cnt += 1;
        int deg = 0;
        bool is_terminal = (make_pair(r, c) == make_pair(sr, sc)) || (make_pair(r, c) == make_pair(M-1, 0));
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (legal(nr, nc)) {
                if (!vis[nr][nc]) {
                    deg += 1;
                }
                if (!bfs_vis[nr][nc]) {
                    bfs_vis[nr][nc] = true;
                    q[b++] = make_pair(nr, nc);
                }
            }
        }
        if (deg == 1 && !is_terminal) {
            return false;
        }
    }
    return n + cnt == N; 
}
 
int dfs(int n, int r, int c) {
    if (n == N) {
        return 1;
    }
    vis[r][c] = true;
    int ans = 0;
    if (cmd[n] == 4) {
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (legal(nr, nc) && vis[nr][nc] == 0 && possible(n+1, nr, nc)) {
                ans += dfs(n+1, nr, nc);
            }
        }
    } else {
        int nr = r + dr[cmd[n]];
        int nc = c + dc[cmd[n]];
        if (legal(nr, nc) && vis[nr][nc] == 0 && possible(n+1, nr,nc)) {
            ans += dfs(n+1, nr, nc);
        }
    }
    vis[r][c] = false;
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie();
    string str; cin >> str;
    for (int i = 0; i < N; i++) {
        switch (str[i]) {
            case 'U': cmd[i] = 0; break;
            case 'D': cmd[i] = 1; break;
            case 'L': cmd[i] = 2; break;
            case 'R': cmd[i] = 3; break;
            case '?': cmd[i] = 4; break;
            default: assert(false); break;
        }
    }
    cout << dfs(0, 0, 0) << "\n";
}
