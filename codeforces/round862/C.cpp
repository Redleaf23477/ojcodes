#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    vector<LL> slope(n);
    for (auto &k : slope) cin >> k;
    sort(slope.begin(), slope.end());
    while (m--) {
        LL a, b, c; cin >> a >> b >> c;
        auto it = lower_bound(slope.begin(), slope.end(), b);
        if (it != slope.end()) {
            LL k = *it;
            if ((b - k) * (b - k) < 4 * a * c) {
                cout << "Yes\n" << k << "\n";
                continue;
            }
        }
        if (it != slope.begin()) {
            it--;
            LL k = *it;
            if ((b - k) * (b - k) < 4 * a * c) {
                cout << "Yes\n" << k << "\n";
                continue;
            }
        }
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}



