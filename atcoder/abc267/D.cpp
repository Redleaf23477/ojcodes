#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL INF = 1e18;

void solve() {
    int N, M; cin >> N >> M;
    vector<LL> A(N);
    for (auto &x : A) cin >> x;

    vector<LL> mx(M + 1, -INF);
    mx[0] = 0, mx[1] = A[0];
    for (int i = 1; i < N; i++) {
        for (int j = M; j > 0; j--) {
            if (mx[j - 1] == -INF) continue;
            mx[j] = max(mx[j], mx[j - 1] + A[i] * j);
        }
    }
    cout << mx[M] << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}