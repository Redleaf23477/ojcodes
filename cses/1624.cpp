#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

string chess[8];
int col_mask, uldr_mask, urdl_mask;

LL dfs(int r) {
    if (r == 8) return 1;
    LL ans = 0;
    for (int c = 0; c < 8; c++) {
        // illegal
        if ((col_mask >> c) & 1) continue;
        if ((uldr_mask >> (r-c+8)) & 1) continue;
        if ((urdl_mask >> (r+c)) & 1) continue;
        if (chess[r][c] != '.') continue;
        // add mask
        chess[r][c] = 'Q';
        col_mask ^= (1 << c);
        uldr_mask ^= (1 << (r-c+8));
        urdl_mask ^= (1 << (r+c));

        ans += dfs(r+1);

        // undo mask
        chess[r][c] = '.';
        col_mask ^= (1 << c);
        uldr_mask ^= (1 << (r-c+8));
        urdl_mask ^= (1 << (r+c));
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    for (int i = 0; i < 8; i++) cin >> chess[i];
    col_mask = uldr_mask = urdl_mask = 0;
    cout << dfs(0) << "\n";
}

