#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int K; cin >> K;
    if (K >= 60) {
        cout << "22:";
        K -= 60;
    } else {
        cout << "21:";
    }
    cout << setw(2) << setfill('0') << K << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



