#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    vector<string> arr(10);
    for (auto &s : arr) cin >> s;
    int u = -1, d = -1, l = -1, r = -1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (arr[i][j] == '#' && l == -1) l = j;
            if (arr[i][j] == '#') r = j;
        }
    }
    for (int j = 0; j < 10; j++) {
        for (int i = 0; i < 10; i++) {
            if (arr[i][j] == '#' && u == -1) u = i;
            if (arr[i][j] == '#') d = i;
        }
    }
    cout << u + 1 << " " << d + 1 << "\n";
    cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}

