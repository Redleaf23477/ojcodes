#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int N; cin >> N;
    vector<vector<int>> arr(2001, vector<int>(2001, 0));
    for (int i = 0; i < N; i++) {
        int x, y; cin >> x >> y;
        arr[x + 1000][y + 1000] = 1;
    }
    vector<int> dr {-1, -1, 0, 0, 1, 1};
    vector<int> dc {-1, 0, -1, 1, 0, 1};
    function<void(int,int)> floodfill = [&](int i, int j) {
        if (i < 0 || i > 2000) return;
        if (j < 0 || j > 2000) return;
        if (arr[i][j] != 1) return;
        arr[i][j] = 2;
        for (int d = 0; d < 6; d++) {
            floodfill(i + dr[d], j + dc[d]);
        }
    };
    int ans = 0;
    for (int i = 0; i < 2001; i++) for (int j = 0; j < 2001; j++) {
        if (arr[i][j] == 1) {
            ans++;
            floodfill(i, j);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}

