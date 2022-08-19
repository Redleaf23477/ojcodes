#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n == 1) cout << 0 << "\n";
        else cout << 2 * n - 3 << "\n";
    }
}

