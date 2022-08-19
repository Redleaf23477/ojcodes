#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    const LL N = 1e7 + 1;
    vector<LL> sp(N, -1), primes;
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i < N; i++) {
        if (sp[i] == i) {
            primes.emplace_back(i);
            for (LL j = i * i; j < N; j += i) {
                if (sp[j] == j) sp[j] = i;
            }
        }
    }
    /*
    for (int i = 0; i < 10; i++) cerr << primes[i] << " ";
    cerr << endl;
    */

    LL n; cin >> n;
    LL ans = -1;
    for (auto p : primes) {
        if (p >= n) break;
        LL q = n - p;
        if (binary_search(primes.begin(), primes.end(), q)) {
            ans = p; break;
        }
    }

    if (ans == -1) cout << -1 << "\n";
    else cout << ans << " " << n - ans << "\n";
}

