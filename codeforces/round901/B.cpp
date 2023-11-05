#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> A(n), B(m);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    for (int round = 1; round <= 10 && round <= k; round++) {
        if (round % 2 == 1) {
            auto x = min_element(A.begin(), A.end());
            auto y = max_element(B.begin(), B.end());
            if (*x < *y) swap(*x, *y);
        } else {
            auto x = min_element(B.begin(), B.end());
            auto y = max_element(A.begin(), A.end());
            if (*x < *y) swap(*x, *y);
        }
    }
    if (k > 10 && (k - 10) % 2 == 1) {
        auto x = min_element(A.begin(), A.end());
        auto y = max_element(B.begin(), B.end());
        if (*x < *y) swap(*x, *y);
    }
    cout << accumulate(A.begin(), A.end(), 0ll) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--) solve();
}

