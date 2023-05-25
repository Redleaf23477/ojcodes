#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    string str; cin >> str;
    if (*max_element(str.begin(), str.end()) == *min_element(str.begin(), str.end())) {
        cout << -1 << "\n";
    } else {
        cout << str.size() - 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



