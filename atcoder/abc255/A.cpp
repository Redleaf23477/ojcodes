#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int R, C; cin >> R >> C; R--, C--;
    vector<vector<int>> M(2, vector<int>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> M[i][j];
        }
    }
    cout << M[R][C] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



