#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int r, c; cin >> r >> c;
    vector<vector<int>> arr(r, vector<int>(c, 0));
    for (int i = 0; i < r; i++) for (int j = 0; j < c; j++) {
        cin >> arr[i][j];
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }
}

