#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr int MOD = 998244353;

constexpr int N = 100000;
vector<int> sp(N+1, 0); 
vector<int> small_primes;

vector<int> decomp(LL div) {
    vector<int> s;
    for (auto p : small_primes) {
        if (div <= N) break;
        if (div % p == 0) {
            s.emplace_back(p);
            while (div % p == 0) div /= p;
        }
        if (div <= N) break;
    }
    if (div <= N) {
        while (div != 1) {
            int f = sp[div];
            if (s.empty() || s.back() != f) s.emplace_back(f);
            div /= f;
        }
    }
    if (div != 1) s.emplace_back(div);
    return s;
}

LL calc(LL m, LL base, vector<int> &fac) {
    int n = fac.size();
    LL ans = 0;
    for (int mask = 1; mask < (1 << n); mask++) {
        LL x = base, cnt = 0;
        for (int i = 0; i < n; i++) if ((mask >> i) & 1) {
            x *= fac[i], cnt++;
        }
        if (cnt % 2 == 0) {
            ans = (ans + MOD - m / x) % MOD;
        } else {
            ans = (ans + m / x) % MOD;
        }
    }
    return (m / base - ans + MOD) % MOD;
}

void solve() {
    LL n, m; cin >> n >> m;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    LL ans = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i-1] % arr[i] != 0) {
            ans = 0; break;
        }
        LL div = arr[i-1] / arr[i];
        vector<int> fac = decomp(div);
        LL choice = calc(m, arr[i], fac);
        /*
        cerr << "i = " << i << ", fac = {";
        for (auto x : fac) cerr << x << " ";
        cerr << "}, choice = " << choice << endl;
        */
        ans = ans * choice % MOD;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    // build prime table
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i <= N; i++) {
        if (sp[i] == i) {
            small_primes.emplace_back(i);
            for (LL j = i * i; j <= N; j += i) {
                sp[j] = i;
            }
        }
    }
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

