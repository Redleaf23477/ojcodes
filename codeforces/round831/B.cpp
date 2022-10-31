#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using T = tuple<LL,LL>;

void solve() {
    int n; cin >> n;
    vector<LL> arr;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        LL a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        ans += 2 * a;
        arr.emplace_back(b);
    }
    LL mx = *max_element(arr.begin(), arr.end());
    ans += 2 * mx;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

