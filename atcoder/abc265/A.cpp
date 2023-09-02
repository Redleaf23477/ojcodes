#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int X, Y, N; cin >> X >> Y >> N;
    Y = min(Y, 3 * X);
    cout << Y * (N / 3) + X * (N % 3) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



