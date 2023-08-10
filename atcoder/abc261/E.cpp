#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, C; cin >> N >> C;
    vector<pair<int,int>> op(N);
    for (auto &[t, x] : op) cin >> t >> x;

    // calc[pref][bit][start from 0/1]
    vector<vector<vector<int>>> calc(N, vector<vector<int>>(30, vector<int>(2, 0)));
    for (int i : {0}) {
        auto [t, x] = op[i];
        for (int b = 0; b < 30; b++) {
            for (int d : {0, 1}) {
                if (t == 1) {
                    calc[i][b][d] = d and ((x >> b) & 1);
                } else if (t == 2) {
                    calc[i][b][d] = d or ((x >> b) & 1);
                } else {
                    calc[i][b][d] = d xor ((x >> b) & 1);
                }
            }
        }
    }
    for (int i = 1; i < N; i++) {
        auto [t, x] = op[i];
        for (int b = 0; b < 30; b++) {
            for (int d : {0, 1}) {
                if (t == 1) {
                    calc[i][b][d] = calc[i-1][b][d] and ((x >> b) & 1);
                } else if (t == 2) {
                    calc[i][b][d] = calc[i-1][b][d] or ((x >> b) & 1);
                } else {
                    calc[i][b][d] = calc[i-1][b][d] xor ((x >> b) & 1);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        int C2 = 0;
        for (int b = 0; b < 30; b++) {
            C2 |= (calc[i][b][(C >> b) & 1] << b);
        }
        C = C2;
        cout << C << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



