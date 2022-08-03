#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<LL> arr(n);
        for (auto &x : arr) cin >> x;
        vector<LL> pre(arr), suf(arr);
        for (int i = 1; i < n; i++) pre[i] += pre[i-1];
        for (int i = n-2; i >= 0; i--) suf[i] += suf[i+1];

        map<LL,int> pre_mp;
        for (int i = 0; i < n; i++) {
            pre_mp[pre[i]] = i + 1;
        }

        LL ans = 0;
        for (int i = 1; i < n; i++) {
            LL s = suf[n-i];
            if (pre_mp.count(s) != 0) {
                LL p = pre_mp[s];
                if (i + p <= n) ans = max(ans, i + p);
            }
        }
        cout << ans << "\n";
    }
}

