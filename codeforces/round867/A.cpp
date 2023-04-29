#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, t; cin >> n >> t;
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    int ans = -2;
    for (int i = 0; i < n; i++) {
        if (i + A[i] <= t) {
            if (ans == -2 || B[i] > B[ans]) {
                ans = i;
            }
        }
    }
    cout << ans + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



