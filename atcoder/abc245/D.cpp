#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n + 1), B(m + 1), C(n + m + 1);
    for (auto &x : A) cin >> x;
    for (auto &x : C) cin >> x;

    int a_front = 0;
    while (A[a_front] == 0) a_front++;

    for (int i = 0; i <= m; i++) {
        B[i] = C[i + a_front] / A[a_front];
        for (int j = a_front; j <= n; j++) {
            C[i + j] -= B[i] * A[j];
        }
    }
    for (auto x : B) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



