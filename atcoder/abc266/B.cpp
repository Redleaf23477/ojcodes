#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    constexpr LL M = 998244353;
    LL N; cin >> N;
    if (N < 0) {
        cout << (M - (-N % M)) % M << "\n";
    } else {
        cout << N % M << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}