#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int dr[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[] = {-2, -1, 1, 2, -2, -1, 1, 2};

int arr[8][8], ans[8][8];

bool legal(int r, int c) {
    return 0 <= r && r < 8 && 0 <= c && c < 8;
}

bool dfs(int r, int c, int step) {
    ans[r][c] = step;
    for (int d = 0; d < 8; d++) {
        int r2 = r + dr[d], c2 = c + dc[d];
        if (legal(r2, c2)) arr[r2][c2] -= 1;
    }

    if (step == 64) {
        for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) {
            cout << ans[i][j] << " \n"[j==7];
        }
        return true;
    }

    int nxt_d[] = {0, 1, 2, 3, 4, 5, 6, 7};
    sort(nxt_d, nxt_d + 8, [&](int lhs, int rhs) {
        int r1 = r + dr[lhs], c1 = c + dc[lhs];
        int r2 = r + dr[rhs], c2 = c + dc[rhs];

        if (!legal(r1, c1) || ans[r1][c1] != 0) return false;
        if (!legal(r2, c2) || ans[r2][c2] != 0) return true;
        return arr[r1][c1] < arr[r2][c2];
    });
    for (auto d : nxt_d) {
        int r2 = r + dr[d], c2 = c + dc[d];
        if (legal(r2, c2) && ans[r2][c2] == 0) {
            if (dfs(r2, c2, step + 1)) return true;
        } else { 
            break;
        }
    }

    ans[r][c] = 0;
    for (int d = 0; d < 8; d++) {
        int r2 = r + dr[d], c2 = c + dc[d];
        if (legal(r2, c2)) arr[r2][c2] += 1;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int r, c; cin >> c >> r; r--, c--;
    for (int i = 0; i < 8; i++) for (int j = 0; j < 8; j++) {
        for (int d = 0; d < 8; d++) {
            arr[i][j] += legal(i + dr[d], j + dc[d]);
        }
    }
    dfs(r, c, 1);
}

