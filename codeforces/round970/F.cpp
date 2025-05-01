#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL MOD = 1e9 + 7;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        p /= 2;
        x = x * x % MOD;
    }
    return ans;
}

LL modinv(LL x) { return fastpw(x, MOD - 2); }

void solve() {
    size_t n; cin >> n;
    vector<LL> arr(n + 1, 0);  // 1-index
    for (size_t i = 1; i <= n; i++) cin >> arr[i];
    vector<LL> pref(arr);
    partial_sum(pref.begin(), pref.end(), pref.begin());

    LL sum = 0;
    for (size_t i = 1; i <= n; i++) {
        LL a = arr[i];
        LL b = (pref[n] - pref[i]) % MOD;
        sum += a * b % MOD;
    }
    sum %= MOD;

    LL div = n * (n - 1) % MOD * modinv(2) % MOD;

    cout << sum * modinv(div) % MOD << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

