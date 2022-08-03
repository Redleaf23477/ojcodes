#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    vector<int> ink(4, 1e6);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            int c; cin >> c;
            ink[j] = min(ink[j], c);
        }
    }
    if (accumulate(ink.begin(), ink.end(), 0) >= 1e6) {
        int acc = 1e6;
        for (int i = 0; i < 4; i++) {
            int v = min(acc, ink[i]);
            cout << v << " \n"[i==3];
            acc -= v;
        }
    } else {
        cout << "IMPOSSIBLE\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

