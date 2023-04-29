#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

pair<int,int> rot(int r, int c, int n) {
    return make_pair(n - r - 1, n - c - 1);
}

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cin >> arr[r][c];
        }
    }
    int diff = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            auto [rr, cc] = rot(r, c, n);
            if (arr[rr][cc] != arr[r][c]) {
                diff++;
            }
        }
    }
    diff /= 2;
    if (diff > k) {
        cout << "No\n";
    } else if (n % 2 == 1) {
        cout << "Yes\n";
    } else if (k % 2 == diff % 2) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



