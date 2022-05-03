#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

LL fastpw(LL x, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p & 1) ans = ans * x % MOD;
        x = x * x % MOD;
        p >>= 1;
    }
    return ans;
}

inline LL add(LL lhs, LL rhs) { return (lhs + rhs >= MOD? lhs + rhs - MOD : lhs + rhs); }
inline LL sub(LL lhs, LL rhs) { return add(lhs, MOD - rhs); }
inline LL mul(LL lhs, LL rhs) { return lhs * rhs % MOD; }
inline LL mod_div(LL lhs, LL rhs) { return mul(lhs, fastpw(rhs, MOD-2)); }

LL num_divisor(vector<tuple<LL,LL>> &fac) {
    LL ans = 1;
    for (auto [f, p] : fac) {
        ans = mul(ans, p+1);
    }
    return ans;
}

LL sum_divisor(vector<tuple<LL,LL>> &fac) {
    LL ans = 1;
    for (auto [f, p] : fac) {
        LL geo = mod_div(sub(fastpw(f, p+1), 1), f-1);
        ans = mul(ans, geo);
    }
    return ans;
}

bool is_square(vector<tuple<LL,LL>> &fac) {
    for (auto [f, p] : fac) {
        if (p % 2 == 1) return false;
    }
    return true;
}

LL square_num_prod_divisor(vector<tuple<LL,LL>> &fac) {
    LL sqrt_num = 1;
    for (auto [f, p] : fac) {
        sqrt_num = mul(sqrt_num, fastpw(f, p/2));
    }
    LL ans = sqrt_num;
    for (auto [f, p] : fac) {
        ans = fastpw(ans, p+1);
    }
    return ans;
}

LL non_square_num_prod_divisor(vector<tuple<LL,LL>> &fac) {
    LL num = 1;
    for (auto [f, p] : fac) {
        num = mul(num, fastpw(f, p));
    }
    LL ans = num;
    bool sqrted = false;
    for (auto [f, p] : fac) {
        if (!sqrted && (p+1) % 2 == 0) {
            ans = fastpw(ans, (p+1)/2);
            sqrted = true;
        } else {
            ans = fastpw(ans, p+1);
        }
    }
    return ans;
}

LL prod_divisor(vector<tuple<LL,LL>> &fac) {
    if (is_square(fac)) return square_num_prod_divisor(fac);
    else return non_square_num_prod_divisor(fac);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<tuple<LL,LL>> fac(n);
    for (auto &[f, p] : fac) cin >> f >> p;

    cout << num_divisor(fac) << " "
        << sum_divisor(fac) << " "
        << prod_divisor(fac) << "\n";
}