#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string str; cin >> str;
    for (int i = 0; i < 3; i++) {
        int same = 0;
        for (int j = 0; j < 3; j++) {
            if (str[i] == str[j]) same++;
        }
        if (same == 1) {
            cout << str[i] << "\n"; return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



