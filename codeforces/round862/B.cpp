#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    for (char ch = 'a'; ch <= 'z'; ch++) {
        for (int i = n-1; i >= 0; i--) {
            if (str[i] == ch) {
                str.erase(i, 1);
                cout << ch + str << "\n";
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



