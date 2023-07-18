#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    vector<vector<int>> pos(N + 1);
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        pos[x].emplace_back(i + 1);
    }
    int Q; cin >> Q;
    while (Q--) {
        int L, R, X; cin >> L >> R >> X;
        auto ub = upper_bound(pos[X].begin(), pos[X].end(), R);
        auto lb = lower_bound(pos[X].begin(), pos[X].end(), L);
        cout << ub - lb << "\n";
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



