#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr int M = 1000000;

void solve() {
    vector<int> sp(M + 1);
    vector<LL> primes;
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i <= M; i++) {
        if (sp[i] != i) continue;
        primes.emplace_back(i);
        for (LL j = i * i; j <= M; j += i) {
            if (sp[j] == j) sp[j] = i;
        }
    }

    vector<LL> p3(primes.size());
    for (size_t i = 0; i < primes.size(); i++) {
        p3[i] = primes[i] * primes[i] * primes[i];
    }

    LL N; cin >> N;
    LL ans = 0;
    for (int i = 0; i < primes.size(); i++) {
        LL q = N / primes[i];
        int j = upper_bound(p3.begin(), p3.end(), q) - p3.begin();
        if (j - 1 > i) ans += j - 1 - i;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



