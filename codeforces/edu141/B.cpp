#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));

    vector<int> dr {1, 0, -1, 0};
    vector<int> dc {0, 1, 0, -1};

    int r = 0, c = 0, dir = 0;
    int num = 1, d = n * n - 1, s = 1;
    for (int i = 0; i < n * n; i++) {
        arr[r][c] = num;
        num = num + d * s;
        s *= -1;
        d--;
        int nr = r + dr[dir], nc = c + dc[dir];
        if (0 <= nr && nr < n && 0 <= nc && nc < n && arr[nr][nc] == 0) {
            r = nr, c = nc;
        } else {
            dir = (dir + 1) % 4;
            r = r + dr[dir], c = c + dc[dir];
        }
    }

    for (auto &row : arr) {
        for (auto x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

