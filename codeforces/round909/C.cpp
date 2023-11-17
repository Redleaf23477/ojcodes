#include <bits/stdc++.h>
using namespace std;
using LL = long long;

LL run(vector<LL> &arr) {
    /*
    cerr << "arr = ";
    for (auto x : arr) cerr << x << " ";
    cerr << endl;
    */
    int n = arr.size();
    LL ans = arr.front();
    LL mn_pref = 0, pref = 0;
    for (int i = 0; i < n; i++) {
        pref += arr[i];
        ans = max(ans, pref - mn_pref);
        mn_pref = min(mn_pref, pref);
    }
    return ans;
}

void solve() {
    int n; cin >> n;
    vector<LL> arr;
    LL ans = -1e9;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        if (arr.empty() || abs(arr.back() % 2) != abs(x % 2)) {
            arr.emplace_back(x);
        } else {
            ans = max(ans, run(arr));
            arr.clear();
            arr.emplace_back(x);
        }
    }
    cout << max(ans, run(arr)) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

