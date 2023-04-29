#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<string> maze(n);
    for (auto &s : maze) cin >> s;

    vector<int> dr {1, 0, 1, 1};
    vector<int> dc {0, 1, -1, 1};
    auto check = [&](int i, int j) {
        for (int d = 0; d < 4; d++) {
            int white = 0;
            for (int cnt = 0; cnt < 6; cnt++) {
                int r = i + cnt * dr[d], c = j + cnt * dc[d];
                if (!(0 <= r && r < n && 0 <= c && c < n)) {
                    white += 100; break;
                } else {
                    white += (maze[r][c] == '.');
                }
            }
            if (white <= 2) return true;
        }
        return false;
    };

    bool good = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            good |= check(i, j);
        }
    }
    cout << (good? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



