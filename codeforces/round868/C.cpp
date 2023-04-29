#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL N = 10'000;
vector<LL> sp(N+1);
vector<LL> primes; // primes <= N

void build_prime_table() {
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i <= N; i++) {
        if (sp[i] == i) {
            primes.emplace_back(i);
            for (LL j = i * i; j <= N; j += i) {
                if (sp[j] == j) sp[j] = i;
            }
        }
    }
}

void solve() {
    map<LL,LL> pfac;
    auto defac = [&](LL x) {
        for (auto p : primes) {
            while (x % p == 0) {
                x /= p;
                pfac[p]++;
            }
        }
        if (x != 1) pfac[x]++;
    };
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        defac(x);
    }
    LL one = 0, two = 0;
    for (auto [p, cnt] : pfac) {
        two += cnt / 2;
        one += cnt % 2;
    }
    LL one_group = one / 3;
    one %= 3;
    if (one_group + two > 0) {
        cout << one_group + two << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    build_prime_table();
    while (T--) {
        solve();
    }
}



