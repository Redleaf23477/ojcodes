#include <bits/stdc++.h>
using namespace std;
using I128 = __int128;
using LL = long long int;

const LL MOD = 998244353;

I128 read_for_128() {
    LL x; cin >> x;
    return x;
}

void print_128(I128 num) {
    LL x = num;
    cout << x << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> sp(n+1);
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i <= n; i++) {
        if (sp[i] == i) {
            for (LL j = i * i; j <= n; j += i) {
                sp[j] = i;
            }
        }
    }
    I128 m = read_for_128();
    I128 unambiguous = [&]() {
        I128 ans = m;
        I128 pref = m;
        I128 lcm = 1;
        for (int i = 2; i <= n; i++) {
            // lcm = x * y / gcd(x, y)
            if (sp[i] == i) {
                lcm = lcm * i;
            }
            if (m / lcm == 0) break;
            pref = pref * (m / lcm) % MOD;
            ans = (ans + pref) % MOD;
        }
        return ans;
    }();
    I128 all = [&]() {
        I128 ans = 0;
        I128 tmp = 1;
        for (int i = 0; i < n; i++) {
            tmp = tmp * m % MOD;
            ans = (ans + tmp) % MOD;
        }
        return ans;
    }();


    I128 ans = ((all - unambiguous) % MOD + MOD) % MOD;
    print_128(ans);
}

