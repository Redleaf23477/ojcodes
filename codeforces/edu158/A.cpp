#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, dest; cin >> n >> dest;
    vector<int> arr(1, 0);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        arr.emplace_back(x);
    }
    int ans = 0;
    for (int i = 1; i < (int)arr.size(); i++) {
        ans = max(ans, arr[i] - arr[i - 1]);
    }
    ans = max(ans, 2 * (dest - arr.back()));
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

