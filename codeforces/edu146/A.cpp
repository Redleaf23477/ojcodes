#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    LL n, k; cin >> n >> k;
    LL q = n / k;
    LL q2 = q - 1;
    if ((n - k * q) % 2 == 0) {
        cout << "Yes\n";
    } else if (q2 >= 0 && (n - k * q2) % 2 == 0) {
        cout << "Yes\n";
    } else if (n % 2 % k == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



