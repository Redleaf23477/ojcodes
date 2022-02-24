#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

constexpr LL MOD = 998244353;

LL fastpw(LL a, LL p) {
    LL ans = 1;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * a % MOD;
        a = a * a % MOD;
        p /= 2;
    }
    return ans;
}

void solve() {
    LL R, C, K, q; cin >> R >> C >> K >> q;
    vector<tuple<int,int>> arr(q);
    for (auto &[r, c] : arr) {
        cin >> r >> c; r--, c--;
    }
    LL cnt = 0;
    set<int> zero_row, zero_col;
    int minus_row = 0, minus_col = 0;
    for (int i = q-1; i >= 0; i--) {
        auto [r, c] = arr[i];
        int rn = (zero_row.count(r) == 0? C : 0);
        int cn = (zero_col.count(c) == 0? R : 0);
        if (rn - minus_row > 0 || cn - minus_col > 0) cnt++;
        if (zero_row.count(r) == 0) minus_col++;
        if (zero_col.count(c) == 0) minus_row++;
        zero_row.insert(r);
        zero_col.insert(c);
    }
    cout << fastpw(K, cnt) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

