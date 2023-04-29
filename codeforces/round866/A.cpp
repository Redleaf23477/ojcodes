#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string s; cin >> s;
    char state = 'x';
    int cnt = 0;
    for (auto ch : s) {
        if (state == 'x') {
            if (ch == '^') state = '^';
            else cnt++, state = '_';
        } else if (state == '^') {
            if (ch == '^') state = '^';
            else state = '_';
        } else {
            if (ch == '^') state = '^';
            else cnt++, state = '_';
        }
    }
    if (state == '_') cnt++;
    else if (s.size() == 1) cnt++;
    cout << cnt << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



