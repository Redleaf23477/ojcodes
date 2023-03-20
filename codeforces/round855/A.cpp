#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    string meow("meow");
    bool found = false;
    int i = 0;
    for (int j = 0; j < n; ) {
        char ch = tolower(str[j]);
        if (ch == meow[i]) {
            found = true;
            j++;
        } else {
            if (found) {
                i++, found = false;
                if (i >= 4) {
                    cout << "NO\n"; return;
                }
            } else {
                cout << "NO\n"; return;
            }
        }
    }
    if (i == 3 && found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

