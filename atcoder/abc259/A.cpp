#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, M, X, T, D; cin >> N >> M >> X >> T >> D;
    if (M >= X) {
        cout << T << "\n";
    } else {
        cout << T - D * (X - M) << "\n";
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



