#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int H, W; cin >> H >> W;
    vector<string> board(H);
    for (auto &s : board) cin >> s;
    vector<pair<int,int>> piece;
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) {
        if (board[i][j] == 'o') {
            piece.emplace_back(i, j);
        }
    }
    cout << abs(piece[0].first - piece[1].first) + abs(piece[0].second - piece[1].second) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



