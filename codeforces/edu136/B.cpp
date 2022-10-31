#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> D(n);
    for (auto &x : D) cin >> x;
    vector<LL> A(n);
    A[0] = D[0];
    for (int i = 1; i < n; i++) {
        A[i] = A[i-1] + D[i];
        if (D[i] != 0 && A[i-1] - D[i] >= 0) {
            cout << -1 << "\n";
            return;
        }
    }
    for (auto x : A) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

