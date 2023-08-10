#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int L1, R1, L2, R2; cin >> L1 >> R1 >> L2 >> R2;
    int len = min(R1, R2) - max(L1, L2);
    if (len < 0) len = 0;
    cout << len << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



