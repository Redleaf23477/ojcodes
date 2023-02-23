#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    string str; cin >> str;
    // first case
    cout << 1 << " ";
    // later case
    int consecutive = 1;
    for (int x = 3; x <= n; x++) {
        if (str[x-2] == str[x-3]) consecutive++;
        else consecutive = 1;
        cout << x - consecutive << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
}

