#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    // inclusion-exclusion
    LL n; cin >> n;
    int k; cin >> k;
    vector<LL> primes(k);
    for (auto &x : primes) cin >> x;

    LL ans = 0;
    for (int mask = 1; mask < (1<<k); mask++) {
        int one_cnt = 0;
        LL divisor = 1;
        for (int i = 0; i < k; i++) {
            int b = (mask >> i) & 1;
            if (b != 0) {
                one_cnt += 1;
                // divisor *= primes[i];
                if (primes[i] > n / divisor) divisor = n + 1;
                else divisor *= primes[i];
            }
        }
        LL sign = (one_cnt % 2 == 0? -1 : 1);
        // cerr << "n = " << n << ", sign = " << sign << ", divisor = " << divisor << endl;
        ans += sign * n / divisor;
    }
    cout << ans << "\n";
}