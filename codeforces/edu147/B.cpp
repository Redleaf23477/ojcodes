#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] != B[i]) {
            if (l == -1) l = i;
            r = i;
        }
    }
    while (l > 0 && B[l-1] <= B[l]) l--;
    while (r < n-1 && B[r] <= B[r+1]) r++;
    cout << l + 1 << " " << r + 1 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



