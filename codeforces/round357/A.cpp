#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    int ans = 0;
    while (n--) {
        string x; cin >> x;
        int a, b; cin >> a >> b;
        if (2400 <= a && b - a > 0) {
            ans++;
        }
    }
    cout << (ans > 0? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



