#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, Q; cin >> N >> Q;
    vector<LL> A(N), X(Q);
    for (auto &a : A) cin >> a;
    for (auto &x : X) cin >> x;
    sort(A.begin(), A.end());

    vector<LL> pref_A(A);
    partial_sum(A.begin(), A.end(), pref_A.begin());

    for (auto x : X) {
        int i = upper_bound(A.begin(), A.end(), x) - A.begin();
        LL ans = 0;
        if (i > 0) ans += x * i - pref_A[i - 1];
        if (i < N) ans += pref_A.back() - (i == 0? 0 : pref_A[i - 1]) - x * (N - i);
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



