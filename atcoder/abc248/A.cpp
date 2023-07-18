#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string str; cin >> str;
    for (int i = 0; i < 10; i++) {
        if (str.find('0' + i) == string::npos) {
            cout << i << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



