#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    bool has_diff = false;
    int zero = str[0] == '0', one = str[0] == '1';
    for (int i = 1; i < n; i++) {
        if (str[i] == '0') zero++;
        else one++;
        if (str[i] != str[i - 1]) has_diff = true;
    }
    if (has_diff || zero > one) {
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

