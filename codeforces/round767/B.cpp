#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL l, r, k; cin >> l >> r >> k;
    LL even = (r - l + 1) / 2 + ((r - l + 1) % 2 == 1 && l % 2 == 0);
    LL odd = (r - l + 1) - even;
    
    if (l == 1 && r == 1) cout << "NO\n";
    else if (r - l <= k) cout << "YES\n";
    else if (odd <= k) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve(); 
    }
}

