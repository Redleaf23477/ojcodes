#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    multiset<LL> s;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        LL x; cin >> x;
        s.erase(s.begin());
        s.insert(x);
    }
    cout << accumulate(s.begin(), s.end(), 0ll) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

