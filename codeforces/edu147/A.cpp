#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string str; cin >> str;
    int ans = 1;
    if (str[0] == '?') ans *= 9;
    else if (str[0] == '0') ans = 0;

    for (int i = 1; i < str.size(); i++) {
        if (str[i] == '?') ans *= 10;
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



