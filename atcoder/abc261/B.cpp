#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    vector<string> table(N);
    for (auto &s : table) cin >> s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (table[i][j] == 'D' && table[j][i] != 'D') {
                cout << "incorrect\n"; return;
            }
            if (table[i][j] == 'W' && table[j][i] != 'L') {
                cout << "incorrect\n"; return;
            }
            if (table[i][j] == 'L' && table[j][i] != 'W') {
                cout << "incorrect\n"; return;
            }
        }
    }
    cout << "correct\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



