#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string s; cin >> s;
    bool upper = false, lower = false, distinct = true;
    vector<bool> vis(128, false);
    for (auto ch : s) {
        if ('A' <= ch && ch <= 'Z') upper = true;
        if ('a' <= ch && ch <= 'z') lower = true;
        if (vis[ch]) distinct = false;
        vis[ch] = true;
    }
    cout << (upper && lower && distinct? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



