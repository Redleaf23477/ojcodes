#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<int,int,int>;
using P = tuple<int,int>;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (auto &r : arr) {
        for (auto &c : r) {
            cin >> c;
        }
    }
    vector<T> ans;
    auto get_color = [&](int r, int c) {
        int k = 0;
        for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            int rr = r + i, cc = c + j;
            if (arr[rr][cc] != 0) {
                if (k == 0) k = arr[rr][cc];
                else if (k != arr[rr][cc]) k = -1;
            }
        }
        return (k > 0? k : 0);
    };
    auto find_2x2 = [&]() {
        for (int r = 0; r+1 < n; r++) for (int c = 0; c+1 < m; c++) {
            int k = get_color(r, c);
            if (k != 0) return T(r, c, k);
        }
        return T(-1, -1, -1);
    };
    auto next_2x2 = [&](int r, int c) {
        for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) {
            int rr = r + i, cc = c + j;
            if (0 <= rr && rr+1 < n && 0 <= cc && cc+1 < m) {
                int k = get_color(rr, cc);
                if (k != 0) return T(rr, cc, k);
            }
        }
        // gg
        return T(-1, -1, -1);
    };
    auto apply = [&](int r, int c, int k) {
        ans.emplace_back(r, c, k);
        int sub = 0;
        for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
            if (arr[r+i][c+j] != 0) sub++;
            arr[r+i][c+j] = 0;
        }
        // cerr << "apply: (" << r << "," << c << ") => " << sub << endl;
        return sub;
    };
    int cnt = n * m;
    queue<P> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    auto [r, c, k] = find_2x2();
    cnt -= apply(r, c, k), vis[r][c] = true;
    q.emplace(r, c);
    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = -1; i <= 1; i++) for (int j = -1; j <= 1; j++) {
            int rr = r + i, cc = c + j;
            if (0 <= rr && rr+1 < n && 0 <= cc && cc+1 < m) {
                int k = get_color(rr, cc);
                if (k != 0) {
                    cnt -= apply(rr, cc, k);
                    if (!vis[rr][cc]) {
                        q.emplace(rr, cc);
                        vis[rr][cc] = true;
                    }
                }
            }
        }
    }
    if (cnt == 0) {
        reverse(ans.begin(), ans.end());
        cout << ans.size() << "\n";
        for (auto [r, c, k] : ans) {
            cout << r+1 << " " << c+1 << " " << k << "\n";
        }
    } else {
        cout << -1 << "\n";
    }
}

