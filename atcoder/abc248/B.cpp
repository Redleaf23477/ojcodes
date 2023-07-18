#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL A, B, K; cin >> A >> B >> K;
    int ans = 0;
    while (A < B) {
        ans++, A *= K;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



