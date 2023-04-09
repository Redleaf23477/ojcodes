#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    int one_pos = -1, n_pos = -1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 1) one_pos = i;
        else if (x == n) n_pos = i;
    }
    cout << max({abs(0-one_pos), abs(0-n_pos), (n-1-one_pos), (n-1-n_pos)}) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



