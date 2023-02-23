#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL P = 100 * 100 + 1;
vector<LL> primes;

void make_prime() {
    vector<int> sp(P, -1);
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i < P; i++) {
        if (sp[i] == i) {
            primes.emplace_back(i);
            for (LL j = i * i; j < P; j += i) {
                if (sp[j] == j) sp[j] = i;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<set<LL>> constraints(primes.size());
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            LL big = max(arr[i], arr[j]);
            LL small = min(arr[i], arr[j]);
            LL sub = big - small;
            if (sub == 0) {
                cout << "NO\n";
                return;
            }
            for (size_t pi = 0; pi < primes.size(); pi++) {
                LL p = primes[pi];
                if (sub % p == 0) {
                    LL r = small % p;
                    constraints[pi].insert((p - r) % p);
                }
            }
        }
    }
    for (size_t pi = 0; pi < primes.size(); pi++) {
        LL p = primes[pi];
        if (constraints[pi].size() == p) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    make_prime();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

