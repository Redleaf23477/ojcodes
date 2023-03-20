#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(256, 0);
    for (int i = 0; i < n; i++) {
        char ch; cin >> ch;
        cnt[ch]++;
    }
    int ans = 0;
    for (char l = 'a', u = 'A'; l <= 'z'; l++, u++) {
        int mn = min(cnt[l], cnt[u]);
        ans += mn;
        cnt[l] -= mn, cnt[u] -= mn;
        if (k > 0) {
            int use = min(k, max(cnt[l], cnt[u]) / 2);
            ans += use;
            k -= use;
        }
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

