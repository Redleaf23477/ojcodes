#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solveB1() {
    int n, m, q; cin >> n >> m >> q;
    vector<int> b(m);
    for (auto &x : b) { cin >> x; x--; }
    sort(b.begin(), b.end());
    while (q--) {
        int a; cin >> a; a--;
        auto it = lower_bound(b.begin(), b.end(), a);
        if (it == b.begin()) {
            cout << b.front() << "\n";
        } else if (it == b.end()) {
            cout << n - 1 - b.back()<< "\n";
        } else {
            int r = *it; it--;
            int l = *it;
            int m = (l + r) / 2;
            cout << min(m - l, r - m) << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solveB1();
}

