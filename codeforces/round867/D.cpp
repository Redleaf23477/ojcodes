#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << 1 << "\n";
    } else if (n % 2 == 1) {
        cout << -1 << "\n";
    } else {
        int l = 0, r = n-1;
        LL sum = 0;
        for (int i = 0; i < n; i += 2) {
            LL x = n - sum + l;
            sum = (sum + x) % n;
            LL y = r - sum;
            sum = (sum + y) % n;
            l++, r--;
            cout << x << " " << y << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



