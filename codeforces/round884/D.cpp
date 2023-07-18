#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    int period = n;
    for (int i = 1; i <= n; i++) {
        if (n % i != 0) {
            period = i; break;
        }
    }
    string ans(n, 'a');
    for (int i = 0; i < n; i++) {
        ans[i] += i % period;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
//    int T = 1;
    while (T--) {
        solve();
    }
}



