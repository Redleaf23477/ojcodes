#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string str; cin >> str;
        str.push_back('W');
        bool ans = true, r = false, b = false;
        char prv = 'W';
        for (auto c : str) {
            if (c == 'R') r = true;
            else if (c == 'B') b = true;
            else if (prv != 'W') {
                ans = ans && r && b;
                r = b = false;
            }
            prv = c;
        }

        cout << (ans? "YES\n" : "NO\n");
    }
}

