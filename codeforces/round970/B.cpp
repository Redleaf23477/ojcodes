#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int get_sq(int n) {
    int sq = sqrt(n);
    for (int x = sq - 1; x <= sq + 1; x++) {
        if (x * x == n) return x;
    }
    return -1;
}

bool is_beautiful(int sq, string &str) {
    // top & bottom
    for (int i = 0; i < sq; i++) {
        if (str[i] != '1') return false;
        if (str.end()[-i-1] != '1') return false;
    }
    // middle
    for (int r = 1; r + 1 < sq; r++) {
        if (str[r * sq] != '1') return false;
        if (str[r * sq + sq - 1] != '1') return false;
        for (int c = 1; c + 1 < sq; c++) {
            if (str[r * sq + c] != '0') return false;
        }
    }
    return true;
}

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    int sq = get_sq(n);
    if (sq == -1) {
        cout << "NO\n"; return;
    }
    if (is_beautiful(sq, str)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

