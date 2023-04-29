#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int R, C; cin >> R >> C;
    int r1, c1; cin >> r1 >> c1;
    int r2, c2; cin >> r2 >> c2;

    auto legal = [&](int r, int c) {
        return 1 <= r && r <= R && 1 <= c && c <= C;
    };

    int cnt1 = 4, cnt2 = 4;
    vector<int> dr {-1, 1, 0, 0};
    vector<int> dc {0, 0, -1, 1};
    for (int d = 0; d < 4; d++) {
        if (!legal(r1 + dr[d], c1 + dc[d])) cnt1--;
        if (!legal(r2 + dr[d], c2 + dc[d])) cnt2--;
    }

    cout << min(cnt1, cnt2) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



