#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    vector<vector<int>> arr(n+1, vector<int>(n+1, 0));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        char ch; cin >> ch;
        arr[i][j] = (ch == '*');
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        arr[i][j] += arr[i][j-1];
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        arr[i][j] += arr[i-1][j];
    }
    while (q--) {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        cout << arr[r2][c2] - arr[r2][c1-1] - arr[r1-1][c2] + arr[r1-1][c1-1] << "\n";
    }

}

