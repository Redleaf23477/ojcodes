#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int ans = 0;
    for (int i = 0; i+1 < n; i++) {
        if (i+2 < n && str[i] == str[i+2]) {
            continue;
        }
        ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



