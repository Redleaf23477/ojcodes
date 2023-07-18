#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int H, W; cin >> H >> W;
    int R, C; cin >> R >> C;
    vector<int> dr {-1, 1, 0, 0};
    vector<int> dc {0, 0, -1, 1};
    int ans = 0;
    for (int d = 0; d < 4; d++) {
        int r = R + dr[d], c = C + dc[d];
        if (1 <= r && r <= H && 1 <= c && c <= W) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



