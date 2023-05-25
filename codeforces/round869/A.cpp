#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    string me; cin >> me;
    int ans = 1;
    for (int i = 1; i < n; i++) {
        string person; cin >> person;
        if (person == me) ans++;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



