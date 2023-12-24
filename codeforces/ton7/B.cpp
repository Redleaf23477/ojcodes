#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int A = -1, B = -1;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'A' && A == -1) A = i;
        if (str[i] == 'B') B = i;
    }
    if (A == -1 || B == -1) {
        cout << 0 << "\n";
    } else if (A > B) {
        cout << 0 << "\n";
    } else {
        cout << B - A << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

