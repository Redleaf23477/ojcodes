#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N, L, R; cin >> N >> L >> R;
    vector<int> A(N);
    for (auto &x : A) cin >> x;
    LL sum = accumulate(A.begin(), A.end(), 0ll);

    vector<LL> left(N, 0);
    left[0] = L - A[0];
    for (int i = 1; i < N; i++) {
        left[i] = left[i - 1] + L - A[i];
    }
    for (int i = 1; i < N; i++) {
        left[i] = min(left[i], left[i - 1]);
    }
    vector<LL> right(N, 0);
    right[N - 1] = R - A[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        right[i] = right[i + 1] + R - A[i];
    }
    for (int i = N - 2; i >= 0; i--) {
        right[i] = min(right[i], right[i + 1]);
    }

    LL ans = min({sum, sum + right[0], sum + left[N - 1]});
    for (int i = 0; i + 1 < N; i++) {
        ans = min(ans, sum + left[i] + right[i + 1]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



