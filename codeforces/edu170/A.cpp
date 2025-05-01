#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    string s, t; cin >> s >> t;
    size_t ans = s.size() + t.size();
    size_t common = 0;
    for (size_t i = 0; i < s.size() && i < t.size(); i++)
        if (s[i] == t[i]) common++;
        else break;
    cout << min(ans, ans - common + 1) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

