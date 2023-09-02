#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int arr[15][15];
    memset(arr, 0, sizeof(arr));
    for (int i = 1; i < 15; i += 2) {
        for (int j = 0; j < 15 - i - i; j++) {
            arr[i][i + j] = 1;
            arr[14 - i][i + j] = 1;
            arr[i + j][i] = 1;
            arr[i + j][14 - i] = 1;
        }
    }
    int r, c; cin >> r >> c;
    cout << (arr[r - 1][c - 1]? "white\n" : "black\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



