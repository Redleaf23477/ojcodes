#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL MOD = 1e9 + 7;

LL fastpw(LL x, LL pw) {
    LL ans = 1;
    while (pw > 0) {
        if (pw % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        pw /= 2;
    }
    return ans;
}

void solve() {
    int T; cin >> T;
    vector<LL> n(T), k(T);
    for (auto &x : n) { cin >> x; x++; }
    for (auto &x : k) { cin >> x; x++; }
    for (int i = 0; i < T; i++) {
        if (k[i] == 1 || k[i] == n[i]) {
            cout << 1 << "\n";
        } else {
            cout << fastpw(2, k[i] - 1) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

