#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    int one = 0, more = 0;
    while (n--) {
        int x; cin >> x;
        one += (x == 1);
        more += (x > 1);
    }
    cout << (one + 1) / 2 + more << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

