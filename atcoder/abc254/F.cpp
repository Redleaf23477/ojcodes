#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

struct SparseTable {
    int n, lg_n;
    vector<vector<int>> st;
    SparseTable(vector<int> const &arr): n(arr.size()), lg_n(log2(n) + 1), st(lg_n + 1, vector<int>(n, 0)) {
        for (int i = 0; i < n; i++) st[0][i] = arr[i];
        for (int len = 1; len <= lg_n; len++) {
            for (int i = 0; i < n; i++) {
                st[len][i] = st[len - 1][i];
                int j = i + (1 << (len - 1));
                if (j < n) st[len][i] = gcd(st[len - 1][i], st[len - 1][j]);
            }
        }
    }
    int query(int L, int R) {
        int lg_len = log2(R - L + 1);
        return gcd(st[lg_len][L], st[lg_len][R - (1 << lg_len) + 1]);
    }
};

void solve() {
    int N, Q; cin >> N >> Q;
    vector<int> A(N), B(N);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    vector<int> diff_A(N, 0), diff_B(N, 0);
    for (int i = 1; i < N; i++) {
        diff_A[i] = abs(A[i] - A[i-1]);
        diff_B[i] = abs(B[i] - B[i-1]);
    }

    SparseTable table_A(diff_A), table_B(diff_B);
    while (Q--) {
        int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
        a1--, a2--, b1--, b2--;
        LL ans = 0;
        if (a2 - a1 > 0) {
            ans = gcd(ans, table_A.query(a1 + 1, a2));
        }
        if (b2 - b1 > 0) {
            ans = gcd(ans, table_B.query(b1 + 1, b2));
        }
        ans = gcd(ans, A[a1] + B[b1]);
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



