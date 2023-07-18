#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL V, A, B, C; cin >> V >> A >> B >> C;
    V %= (A + B + C);
    if (V < A) { cout << "F\n"; return; }
    V -= A;
    if (V < B) { cout << "M\n"; return; }
    V -= B;
    if (V < C) { cout << "T\n"; return; }
    V -= C;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



