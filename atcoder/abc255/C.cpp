#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL X, A, D, N; cin >> X >> A >> D >> N;
    X -= A;

    if (D == 0) {
        cout << abs(X) << "\n";
    } else if ((X <= 0 && D > 0) || (X >= 0 && D < 0)) {
        cout << abs(X) << "\n";
    } else {
        D = abs(D), X = abs(X), N--;
        if (D * N <= X) {
            cout << abs(X - D * N) << "\n";
        } else {
            LL q = X / D;
            cout << min(abs(X - D * q), abs(X - D * (q + 1))) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



