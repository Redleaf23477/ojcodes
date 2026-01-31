#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, c; cin >> n >> c; c -= 1;
    vector<string> grid(n);
    for (auto &row : grid) cin >> row;

    vector<bool> col_clear(n, false);
    for (int j = 0; j < n; j++) {
        if (grid[n - 1][j] == '.') {
            col_clear[j] = true;
        }
    }

    vector<int> dc_list {-1, 0, 1};
    set<int> ok {c};
    for (int i = n - 1; i > 0; i--) {
        // push from i to i - 1
        set<int> next_ok;
        for (auto c : ok) {
            for (auto dc : dc_list) {
                int next_c = c + dc;
                if (next_c < 0 || next_c >= n) {
                    continue;
                }

                if (col_clear[next_c]) {
                    grid[i - 1][next_c] = '.';
                }

                if (grid[i - 1][next_c] == '.') {
                    next_ok.insert(next_c);
                }
            }
        }

        for (int j = 0; j < n; j++) {
            if (col_clear[j] && grid[i - 1][j] != '.') {
                col_clear[j] = false;
            }
        }

        ok = move(next_ok);
    }

    string ans(n, '0');
    for (auto c : ok) {
        ans[c] = '1';
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

