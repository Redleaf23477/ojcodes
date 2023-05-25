#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr int N = 1e6;

vector<int> sp(N+1);
void build_prime_table() {
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i <= N; i++) {
        if (sp[i] == i) {
            for (LL j = i * i; j <= N; j += i) {
                if (sp[j] == j) sp[j] = i;
            }
        }
    }
}

void solve() {
    LL n, m; cin >> n >> m;
    if (n == 1) {
        cout << "YES\n";
    } else if (m >= n) {
        cout << "NO\n";
    } else {
        if (sp[n] > m) cout << "YES\n";
        else cout << "NO\n";
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



