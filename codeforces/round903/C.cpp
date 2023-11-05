#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int m = n / 2;

    auto fix = [&](int i, int j) {
        vector<char> tmp {arr[i][j], arr[j][n-1-i], arr[n-1-i][n-1-j], arr[n-1-j][i]};
        int ans = 0;
        char ch = *max_element(tmp.begin(), tmp.end());
        for (auto x : tmp) ans += ch - x;
        return ans;
    };

    int ans = 0;
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) {
        ans += fix(i, j);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

