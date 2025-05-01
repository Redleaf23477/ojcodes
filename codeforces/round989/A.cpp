#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL a, b; cin >> a >> b;
    // m % a == m % b == r
    // m = ax + r = by + r
    cout << a * b / gcd(a, b) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

