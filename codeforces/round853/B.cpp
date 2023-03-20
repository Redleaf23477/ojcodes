#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int magic = -2;
    bool good = true;
    for (int l = 0, r = n - 1; l < r; l++, r--) {
        if (magic == -2) {
            if (str[l] == str[r]) {
                continue;
            } else {
                magic = -1;
            }
        }
        if (magic == -1) {
            if (str[l] != str[r]) {
                continue;
            } else {
                magic = r;
            }
        }
        if (magic >= 0) {
            if (str[l] == str[r]) {
                continue;
            } else {
                good = false; break;
            }
        }
    }
    cout << (good? "Yes\n" : "No\n");
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

