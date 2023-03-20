#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    auto good = [&](int s) {
        for (int i = 0; i < n; s++) {
            if (s % 3 == 0) {
                if (str[i] != 'F') {
                    return false;
                }
                i++;
            }
            if (i >= n) break;
            if (s % 5 == 0) {
                if (str[i] != 'B') {
                    return false;
                }
                i++;
            }
        }
        return true;
    };
    auto special = [&]() {
        if (str[0] != 'B') return false;
        for (int i = 1, s = 1; i < n; s++) {
            if (s % 3 == 0) {
                if (str[i] != 'F') {
                    return false;
                }
                i++;
            }
            if (i >= n) break;
            if (s % 5 == 0) {
                if (str[i] != 'B') {
                    return false;
                }
                i++;
            }
        }
        return true;
    };
    for (int x = 1; x <= 15; x++) {
        if (good(x)) {
            cout << "Yes\n"; return;
        }
    }
    if (special()) {
        cout << "Yes\n"; return;
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

