#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    string s, op; cin >> s >> op;
    string stk;
    for (auto x : op) {
        if (stk.empty()) {
            stk.push_back(s.back()); s.pop_back();
        }
        while (!s.empty() && s.back() == stk.back()) {
            stk.push_back(s.back()); s.pop_back();
        }
        if (s.empty()) {
            cout << "NO\n"; return;
        }
        if (stk.back() != x) stk.pop_back();
        else s.pop_back();
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}
