#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int query(int r, int c) {
    cout << "? " << r << " " << c << endl;
    int res; cin >> res;
    return res;
}

void report(int r, int c) {
    cout << "! " << r << " " << c << endl;
    return;
}

void solve() {
    int R, C; cin >> R >> C;
    int q1, q2 = R + C, q3 = R + C;

    q1 = query(1, 1);
    // answer lies in (1, k) --- (k, k) and (k, 1) --- (k, k)
    if (1 + q1 <= C) {
        q2 = query(1, 1 + q1);
    } 
    if (1 + q1 <= R) {
        q3 = query(1 + q1, 1);
    }

    if (q2 <= q3) report(1 + q2, 1 + q1);
    else report(1 + q1, 1 + q3);
}

int main() {
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



