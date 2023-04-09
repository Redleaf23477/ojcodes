#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    for (int x = 0; x < (1<<8); x++) {
        int xor_sum = 0;
        for (int i = 0; i < n; i++) {
            xor_sum ^= arr[i] ^ x;
        }
        if (xor_sum == 0) {
            cout << x << "\n"; return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



