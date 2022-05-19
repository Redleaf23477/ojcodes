#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    LL n; cin >> n;
    string str; cin >> str;
    auto [r, matched] = [](string &s) -> pair<int,int> {
        stack<char> stk;
        int matched = 0;
        for (auto c : s) {
            if (c == '(') stk.emplace(c);
            else if (!stk.empty()) stk.pop(), matched += 1;
            else return pair<int,int>(-1, -1);
        }
        return pair<int,int>(stk.size(), matched);
    }(str);

    vector<LL> fac(2 * n + 1, 1), fac_inv(2 * n + 1, 1);
    for (int i = 2; i < (int)fac.size(); i++) {
        fac[i] = fac[i-1] * i % MOD;
    }
    fac_inv[2 * n] = fastpw(fac[2 * n], MOD-2);
    for (LL suff = 2 * n, i = 2 * n - 1; i > 0; suff = suff * i % MOD, i--) {
        fac_inv[i] = fac_inv[2 * n] * suff % MOD;
    }

    for (int i = 2 * n; i >= 0; i--) {
        if (fac[i] * fac_inv[i] % MOD != 1) {
            cerr << "i = " << i << " GG" << endl;
            assert(false);
        }
    }


    auto C = [&fac, &fac_inv](LL a, LL b) {
        // cerr << "a = " << a << ", b = " << b << endl;
        if (b > a || b < 0) return 0ll;
        return fac[a] * fac_inv[b] % MOD * fac_inv[a - b] % MOD;
    };

    if (n % 2 == 1 || r == -1 || r * 2 > n) {
        cout << 0 << "\n";
    } else {
        n -= 2 * matched;
        n /= 2;
        cout << ((C(2 * n - r, n - r) - C(2 * n - r, n - r - 1)) % MOD + MOD) % MOD << "\n";
    }
}