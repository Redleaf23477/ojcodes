#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> A(n), B(n);
    for (auto &a : A) cin >> a;
    for (auto &b : B) cin >> b;

    LL sum_a = accumulate(A.begin(), A.end(), 0ll);
    LL sum_b = accumulate(B.begin(), B.end(), 0ll);

    LL ans = sum_a + sum_b;
    for (auto b : B) {
        ans = min(ans, sum_a + sum_b - b);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

