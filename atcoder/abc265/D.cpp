#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    LL P, Q, R; cin >> P >> Q >> R;
    vector<LL> A(N + 1, 0);
    for (int i = 1; i <= N; i++) cin >> A[i];
    partial_sum(A.begin(), A.end(), A.begin());

    auto good = [&](int start) {
        auto L = A.begin() + start;
        for (auto x : {P, Q, R}) {
            auto it = lower_bound(L, A.end(), *(L - 1) + x);
            if (it == A.end() || *it != *(L - 1) + x) {
                return false;
            }
            L = it + 1;
        }
        return true;
    };

    for (int i = 1; i <= N; i++) {
        if (good(i)) {
            cout << "Yes\n"; return;
        }
    }
    cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



