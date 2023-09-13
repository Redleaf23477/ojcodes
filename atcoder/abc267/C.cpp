#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int N, M; cin >> N >> M;
    vector<LL> arr(N);
    for (auto &x : arr) cin >> x;
    vector<LL> pref(N);
    partial_sum(arr.begin(), arr.end(), pref.begin());
    LL window = 0;
    for (int i = 0; i < M; i++) window += (i + 1) * arr[i];
    LL ans = window;
    for (int i = M; i < N; i++) {
        window -= pref[i - 1] - (i - M - 1 >= 0? pref[i - M - 1] : 0);
        window += M * arr[i];
        ans = max(ans, window);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}