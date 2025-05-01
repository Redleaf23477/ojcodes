#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    string str; cin >> str;
    for (auto ch : str) {
        if (ch == '.') continue;
        cout << ch;
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

