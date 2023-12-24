#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;

    // hit 0
    for (int i = 1; i < n; i++) arr[i] += i;
    vector<LL> suf_max(arr);
    for (int i = n - 2; i >= 0; i--) {
        suf_max[i] = max(suf_max[i], suf_max[i + 1]);
    }
    LL ans = suf_max[0];

    /*
    cerr << "suf_max = ";
    for (auto x : suf_max) cerr << x << " ";
    cerr << endl;
    */

    LL pref_max = 0;
    for (int i = 1; i < n; i++) {
        arr[i] -= i;
        arr[i - 1] += 1 + (n - i - 1);
        pref_max = max(pref_max, arr[i - 1]);
        LL tmp = max(arr[i], arr[i - 1]);
        if (i != n - 1) tmp = max(tmp, suf_max[i + 1]);
        // cerr << "tmp[" << i << "] = " << tmp << endl;
        ans = min(ans, max(pref_max, tmp));
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

