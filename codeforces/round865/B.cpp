#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<vector<int>> arr(2, vector<int>(n, 0));
    arr[0][0] = 2 * n;
    arr[1][n-1] = 2 * n - 1;
    int small = 1, big = 2 * n - 2;
    for (int i = 0; i < n; i += 2) {
        arr[1][i] = small, small++;
        arr[0][i+1] = small, small++;
    }
    for (int i = 1; i < n-1; i += 2) {
        arr[0][i+1] = big, big--;
        arr[1][i] = big, big--;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
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



