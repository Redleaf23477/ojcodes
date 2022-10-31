#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> row(n, 0), col(n, 0);
    vector<tuple<int,int>> rooks(m);
    for (auto &[r, c] : rooks) {
        cin >> r >> c; r--, c--;
        row[r]++, col[c]++;
    }
    bool ans = false;
    for (auto [r, c] : rooks) {
        row[r]--, col[c]--;
        int row_max = *max_element(row.begin(), row.end());
        int col_max = *max_element(col.begin(), col.end());
        int row_zero = 0, col_zero = 0;
        for (int i = 0; i < n; i++) {
            if (row[i] == 0) row_zero++;
            if (col[i] == 0) col_zero++;
        }
        if (row_max <= 1 && col_max <= 1 && row_zero > 0 && col_zero > 0 && row_zero + col_zero > 2) {
            ans = true;
        }
        row[r]++, col[c]++;
    }
    cout << (ans? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

