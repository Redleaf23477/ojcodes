#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    const int N = 10;
    vector<string> board(N);
    for (auto &row : board) cin >> row;
    auto legal = [&](int i, int j) {
        return 0 <= i && i < N && 0 <= j && j < N;
    };
    auto good = [&](int i, int j) {
        if (board[i][j] != '.') return false;

        vector<int> dr {0, 0, 1, -1, 1, 1, -1, -1};
        vector<int> dc {1, -1, 0, 0, 1, -1, 1, -1};

        board[i][j] = 'X';

        for (size_t d = 0; d < dr.size(); d++) {
            for (int r = 0; r < N; r++) for (int c = 0; c < N; c++) {
                int combo = 0;
                for (int s = 0; s < 5; s++) {
                    int rr = r + dr[d] * s, cc = c + dc[d] * s;
                    if (legal(rr, cc) && board[rr][cc] == 'X') combo++;
                }
                if (combo == 5) return true;
            }
        }

        board[i][j] = '.';
        return false;
    };
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (good(i, j)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    solve();
}

