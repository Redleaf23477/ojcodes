#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    char ans = 'A' + (k - 1) / n;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



