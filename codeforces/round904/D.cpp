#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    LL n; cin >> n;
    vector<LL> cnt(n + 1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        cnt[x]++;
    }
    if (cnt[1] != 0) {
        cout << 0 << "\n"; return;
    }
    vector<LL> pair_with_gcd(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        for (int j = i; j <= n; j += i) {
            pair_with_gcd[i] += cnt[j];
        }
    }
    for (int i = 2; i <= n; i++) {
        LL &x = pair_with_gcd[i];
        x = x * (x - 1) / 2;
    }
    for (int i = n; i > 1; i--) {
        for (int j = i + i; j <= n; j += i) {
            pair_with_gcd[i] -= pair_with_gcd[j];
        }
    }
    /*
    for (int i = 0; i <= n; i++) {
        cerr << "cnt[" << i << "] = " << cnt[i] << endl;
    }
    for (int i = 0; i <= n; i++) {
        cerr << "pair_with_gcd[" << i << "] = " << pair_with_gcd[i] << endl;
    }
    */
    vector<bool> substract(n + 1, false);
    for (int i = 2; i <= n; i++) {
        if (cnt[i] == 0) continue;
        for (int j = i; j <= n; j += i) {
            substract[j] = true;
        }
    }
    LL ans = n * (n - 1) / 2;
    for (int i = 2; i <= n; i++) {
        if (substract[i]) ans -= pair_with_gcd[i];
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

