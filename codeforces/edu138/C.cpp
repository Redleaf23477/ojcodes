#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool good(int k, int n, map<int,int> cnt) {
    for (int i = 1; i <= k; i++) {
        int x = k - i + 1;
        // Alice
        auto it = cnt.upper_bound(x);
        if (cnt.empty()) return false;
        if (it == cnt.begin()) return false;
        it--;
        if (--it->second == 0) cnt.erase(it);
        // Bob
        if (cnt.begin() != cnt.end()) {
            if (--cnt.begin()->second == 0) {
                cnt.erase(cnt.begin());
            }
        }
    }
    return true;
}

void solve() {
    int n; cin >> n;
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (cnt.count(x) == 0) cnt[x] = 0;
        cnt[x] += 1;
    }
    int ans = 0;
    for (int k = 1; k <= n; k++) {
        if (good(k, n, cnt)) ans = k;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

