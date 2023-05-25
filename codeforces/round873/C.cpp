#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL MOD = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    LL ans = 1;
    for (int i = 0; i < n; i++) {
        auto lb = lower_bound(B.begin(), B.end(), A[i]);
        if (lb == B.begin()) {
            ans = 0;
        } else {
            LL cnt = lb - B.begin();
            cnt -= i;
            if (cnt <= 0) ans = 0;
            else ans = ans * cnt % MOD;
        }
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



