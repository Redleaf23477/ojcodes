#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
 
constexpr int N = 48, M = 7;
constexpr int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
 
int cmd[N];
int H[N+1], V[N+1], Q[N+1];
bool vis[M][M], bfs_vis[M][M];
 
inline bool legal(int r, int c) {
    return 0 <= r && r < M && 0 <= c && c < M;
}
 
inline bool possible(int n, int nr, int nc) {
    memcpy(bfs_vis, vis, sizeof(vis));
    bfs_vis[nr][nc] = true;
    int cnt = 0;
    queue<pair<int,int>> q;
    if (bfs_vis[M-1][0] == false) {
        q.emplace(M-1, 0); bfs_vis[M-1][0] = true;
    }
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        cnt += 1;
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (legal(nr, nc) && !bfs_vis[nr][nc]) {
                bfs_vis[nr][nc] = true;
                q.emplace(nr, nc);
            }
        }
    }
    return n + cnt == N; 
}
 
// string stk(48, 'x');
 
int dfs(int n, int r, int c) {
    if (n == N) {
//        cerr << stk << endl;
        return 1;
    }
    vis[r][c] = true;
    vector<pair<int,int>> cand;
    if (cmd[n] == 4) {
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (legal(nr, nc) && vis[nr][nc] == 0) {
                cand.emplace_back(nr, nc);
            }
        }
    } else {
        int nr = r + dr[cmd[n]];
        int nc = c + dc[cmd[n]];
        if (legal(nr, nc) && vis[nr][nc] == 0) {
            cand.emplace_back(nr, nc);
        }
    }
    int ans = 0;
    for (auto [nr, nc] : cand) {
        if (possible(n+1, nr, nc)) {
//            for (int d = 0; d < 4; d++) {
//                if (nr == r + dr[d] && nc == c + dc[d]) {
//                    if (d == 0) stk[n] = 'U';
//                    else if (d == 1) stk[n] = 'D';
//                    else if (d == 2) stk[n] = 'L';
//                    else stk[n] = 'R';
//                }
//            }
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
    /*
       for (int i = N-1; i >= 0; i--) {
       Q[i] = Q[i+1] + (cmd[i] == 4);
       H[i] = H[i+1] + (cmd[i] == 4? 0 : dr[cmd[i]] + dc[cmd[i]]);
       V[i] = V[i+1] + (cmd[i] == 4? 0 : dr[cmd[i]] + dc[cmd[i]]);
       }
       */
    cout << dfs(0, 0, 0) << "\n";
}
