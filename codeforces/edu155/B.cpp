#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<LL> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    LL Asum = accumulate(A.begin(), A.end(), 0ll);
    LL Bsum = accumulate(B.begin(), B.end(), 0ll);
    LL Amin = *min_element(A.begin(), A.end());
    LL Bmin = *min_element(B.begin(), B.end());

    cout << min(Amin * n + Bsum, Bmin * n + Asum) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
}

