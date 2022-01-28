#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int R, C; cin >> R >> C;
        int ans = R - (R+1)/2 + C - (C+1)/2;
        vector<vector<bool>> vis(R+1, vector<bool>(C+1, false));
        queue<tuple<int,int,int>> q;

        vector<int> init_r, init_c;
        if (R % 2 == 0) { init_r.emplace_back(R/2), init_r.emplace_back(R/2+1); }
        else init_r.emplace_back((R+1)/2);
        if (C % 2 == 0) { init_c.emplace_back(C/2), init_c.emplace_back(C/2+1); }
        else init_c.emplace_back((C+1)/2);
        for (auto r : init_r) for (auto c : init_c) {
            q.emplace(r, c, 0);
            vis[r][c] = true;
        }

        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, 1, -1};
        while (!q.empty()) {
            auto [r, c, len] = q.front(); q.pop();
            cout << ans + len << " ";
            for (int d = 0; d < 4; d++) {
                int r2 = r + dr[d], c2 = c + dc[d];
                if (1 <= r2 && r2 <= R && 1 <= c2 && c2 <= C) {
                    if (!vis[r2][c2]) {
                        vis[r2][c2] = true;
                        q.emplace(r2, c2, len+1);
                    }
                }
            }
        }
        cout << "\n";
    }
}

