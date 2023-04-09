#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    vector<int> cnt(10, 0);
    int diff = 0;
    for (int i = 0; i < 4; i++) {
        char x; cin >> x;
        if (cnt[x-'0'] == 0) {
            diff++;
        }
        cnt[x-'0']++;
    }
    if (diff == 1) {
        cout << -1 << "\n";
    } else if (diff == 2) {
        if (*max_element(cnt.begin(), cnt.end()) == 3) {
            cout << 6 << "\n";
        } else {
            cout << 4 << "\n";
        }
    } else {
        cout << 4 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



