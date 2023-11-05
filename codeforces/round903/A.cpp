#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, m; cin >> n >> m;
    bool flag = false;
    string x, s; cin >> x >> s;
    for (int i = 0; i < 26; i++) {
        if (x.find(s) != x.npos) {
            cout << i << "\n"; return;
        }
        if (flag) break;
        if (x.size() >= s.size()) {
            flag = true;
        }
        x = x + x;
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

