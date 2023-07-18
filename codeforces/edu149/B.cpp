#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int ans = 1;
    for (int i = 1, acc = 1; i < n; i++) {
        if (str[i] == str[i-1]) {
            acc++;
            ans = max(ans, acc);
        } else {
            ans = max(ans, acc);
            acc = 1;
        }
    }
    cout << ans + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



