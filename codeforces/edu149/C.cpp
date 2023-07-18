#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string str; cin >> str;
    int n = str.size();
    for (int i = 0; i < n; i++) {
        if (str[i] == '?') str[i] = '0';
        else break;
    }
    for (int i = n-1; i >= 0; i--) {
        if (str[i] == '?') str[i] = '1';
        else break;
    }
    for (int i = 0; i < n; i++) {
        if (str[i] == '?') str[i] = str[i-1];
    }
    cout << str << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



