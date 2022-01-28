#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

string chess[8];
int row_mask, col_mask, uldr_mask, urdl_mask;

bool good(int r, int c) {
    if (chess[r][c] != '.') return false;
    if ((row_mask >> r) & 1) return false;
    if ((col_mask >> c) & 1) return false;
    if ((uldr_mask >> (r-c+8)) & 1) return false;
    if ((urdl_mask >> (r+c)) & 1) return false;
    return true;
}

LL dfs(int n, int min_r) {
    if (n == 0) return 1;
    LL ans = 0;
    for (int r = min_r; r < 8; r++) {
        if ((row_mask >> r) & 1) continue;
        for (int c = 0; c < 8; c++) {
            // illegal
            if ((col_mask >> c) & 1) continue;
            if ((uldr_mask >> (r-c+8)) & 1) continue;
            if ((urdl_mask >> (r+c)) & 1) continue;
            if (chess[r][c] != '.') continue;
            // add mask
            chess[r][c] = 'Q';
            row_mask ^= (1 << r);
            col_mask ^= (1 << c);
            uldr_mask ^= (1 << (r-c+8));
            urdl_mask ^= (1 << (r+c));

            ans += dfs(n-1, r+1);

            // undo mask
            chess[r][c] = '.';
            row_mask ^= (1 << r);
            col_mask ^= (1 << c);
            uldr_mask ^= (1 << (r-c+8));
            urdl_mask ^= (1 << (r+c));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    for (int i = 0; i < 8; i++) cin >> chess[i];
    row_mask = col_mask = uldr_mask = urdl_mask = 0;
    cout << dfs(8, 0) << "\n";
}

