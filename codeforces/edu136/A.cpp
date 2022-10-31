#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int R, C; cin >> R >> C;
        int ans_r = 0, ans_c = 0;
        vector<int> dr {-2, -2, -1, -1, 1, 1, 2, 2};
        vector<int> dc {1, -1, 2, -2, 2, -2, 1, -1};
        for (int r = 0; r < R; r++) for (int c = 0; c < C; c++) {
            int good = 0;
            for (int d = 0; d < 8; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (0 <= nr && nr < R && 0 <= nc && nc < C) {
                    good++;
                }
            }
            if (good == 0) {
                ans_r = r, ans_c = c;
            }
        }
        cout << ans_r + 1 << " " << ans_c + 1 << "\n";
    }
}

