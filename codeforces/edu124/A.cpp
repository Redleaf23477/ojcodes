#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        LL n; cin >> n;
        cout << (1ll<<n) - 1 << "\n";
    }
}

