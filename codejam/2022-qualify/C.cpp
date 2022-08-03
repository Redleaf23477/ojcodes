#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    constexpr int B = 1e6 + 1;
    int n; cin >> n;
    vector<int> bucket(B, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        bucket[x] += 1;
    }
    int ans = 0;
    for (int i = 0; i < B; i++) {
        while (bucket[i] > 0 && i > ans) {
            bucket[i] -= 1, ans += 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

