#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    if (A.back() > B.back()) swap(A.back(), B.back());

    for (int i = 0; i < n; i++) {
        if (A[i] > A.back()) {
            swap(A[i], B[i]);
        }
    }

    if (*max_element(A.begin(), A.end()) == A.back() && *max_element(B.begin(), B.end()) == B.back()) {
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



