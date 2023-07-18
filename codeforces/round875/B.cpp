#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<LL> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    vector<vector<int>> cnt(sqrt(2*n) + 2, vector<int>(n+1, 0));
    for (int i = 0; i < n; i++) {
        if (A[i] < (LL)cnt.size()) {
            cnt[A[i]][B[i]]++;
        }
    }

    
    // consider all (i, j) s.t. (ai = aj)
    LL ans1 = 0;
    for (int i = 0; i < n; i++) {
        // (ai, bi) should find (aj = ai, bj = ai * ai - bi) where (i != j)
        LL a = A[i], b = A[i] * A[i] - B[i];
        if (a < (LL)cnt.size() && 0 < b && b < (LL)cnt[a].size()) {
            LL tmp = cnt[A[i]][A[i] * A[i] - B[i]];
            if (B[i] == A[i] * A[i] - B[i]) tmp--;
            ans1 += tmp;
        }
    }
    ans1 /= 2;

    // consider all (i, j) s.t. (ai != aj)
    LL ans2 = 0;
    for (int i = 0; i < n; i++) {
        for (LL a = 1; a < A[i] && a * A[i] <= 2 * n; a++) {
            LL b = A[i] * a - B[i];
            if (0 < (LL)cnt.size() && 0 < b && b < (LL)cnt[a].size()) {
                ans2 += cnt[a][b];
            }
        }
    }

    cout << ans1 + ans2 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



