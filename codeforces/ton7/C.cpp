#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, x; cin >> n >> x;
    vector<pair<int,int>> A(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        A[i] = make_pair(x, i);
    }
    sort(A.begin(), A.end());

    vector<int> B(n);
    for (auto &x : B) cin >> x;
    sort(B.begin(), B.end());

    vector<int> ans(n);
    for (int i = 0; i < x; i++) {
        // put B[i] to sorted_A[n - x + i]
        if (A[n - x + i].first <= B[i]) {
            cout << "NO\n"; return;
        }
        ans[A[n - x + i].second] = B[i];
    }
    for (int i = 0; i < n - x; i++) {
        // put B[x + i] to sorted_A[i]
        if (B[x + i] < A[i].first) {
            cout << "NO\n"; return;
        }
        ans[A[i].second] = B[x + i];
    }

    cout << "YES\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

