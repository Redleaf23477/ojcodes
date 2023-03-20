#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string a(0, 'x'), b(0, 'x');
    for (int i = 0; i < 2 * (n - 1); i++) {
        string s; cin >> s;
        if (s.size() > a.size()) swap(s, a);
        else if (s.size() > b.size()) swap(s, b);
    }
    string s;
    if (a.size() == 1) {
        s = a + b;
    } else if (a.substr(1, a.size() - 1) == b.substr(0, a.size() - 1)) {
        // a-b
        s = a + b.back();
    } else {
        // b-a
        s = b + a.back();
    }
    auto palin = [](string &s) {
        for (int l = 0, r = s.size() - 1; l < r; l++, r--) {
            if (s[l] != s[r]) return false;
        }
        return true;
    };
    cout << (palin(s)? "YES\n" : "NO\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



