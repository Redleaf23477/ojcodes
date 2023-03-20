#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string pi = "314159265358979323846264338327";
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == pi[i]) ans++;
        else break;
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



