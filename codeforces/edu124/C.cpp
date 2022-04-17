#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr LL INF = 1ll << 50;

void solve() {
    int n; cin >> n;
    vector<LL> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    auto C = [](LL a, LL b) { return (LL)abs(a - b); };
    auto find_min = [&](LL x, vector<LL> &arr) {
        LL res = INF;
        for (auto y : arr) res = min(res, C(x, y));
        return res;
    };
    
    // strategy 2
    LL ans = min(C(A[0], B[0]) + C(A[n-1], B[n-1]), C(A[0], B[n-1]) + C(A[n-1], B[0]));

    // strategy 3
    ans = min(ans, C(A[0], B[0]) + C(A[0], B[n-1]) + find_min(A[n-1], B));
    ans = min(ans, C(A[n-1], B[0]) + C(A[n-1], B[n-1]) + find_min(A[0], B));
    ans = min(ans, C(B[0], A[0]) + C(B[0], A[n-1]) + find_min(B[n-1], A));
    ans = min(ans, C(B[n-1], A[0]) + C(B[n-1], A[n-1]) + find_min(B[0], A));

    ans = min(ans, C(A[0], B[0]) + find_min(A[n-1], B) + find_min(B[n-1], A));
    ans = min(ans, C(A[0], B[n-1]) + find_min(A[n-1], B) + find_min(B[0], A));
    ans = min(ans, C(A[n-1], B[0]) + find_min(A[0], B) + find_min(B[n-1], A));
    ans = min(ans, C(A[n-1], B[n-1]) + find_min(A[0], B) + find_min(B[0], A));

    // strategy 4
    ans = min(ans, find_min(A[0], B) + find_min(A[n-1], B) + find_min(B[0], A) + find_min(B[n-1], A));

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

