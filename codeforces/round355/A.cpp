#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, h; cin >> n >> h;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ans += (x > h? 2 : 1);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



