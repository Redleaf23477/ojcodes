#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int R, C; cin >> R >> C;
    vector<vector<pair<int,int>>> arr(R, vector<pair<int,int>>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char ch; cin >> ch;
            if (ch == 'U') arr[i][j] = make_pair(-1, 0);
            else if (ch == 'D') arr[i][j] = make_pair(1, 0);
            else if (ch == 'L') arr[i][j] = make_pair(0, -1);
            else arr[i][j] = make_pair(0, 1);
        }
    }

    vector<vector<bool>> vis(R, vector<bool>(C, 0));
    for (int r = 0, c = 0; !vis[r][c]; ) {
        auto [dr, dc] = arr[r][c];
        int nr = r + dr, nc = c + dc;
        if (nr < 0 || R <= nr || nc < 0 || C <= nc) {
            cout << r + 1 << " " << c + 1 << "\n";
            return;
        }
        vis[r][c] = true;
        r += dr, c += dc;
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



