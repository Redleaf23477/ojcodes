#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int Y; cin >> Y;
    while (Y % 4 != 2) {
        Y++;
    }
    cout << Y << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



