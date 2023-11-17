#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, q; cin >> n >> q;
    // 1-2-3-...-n  rhs
    //   |  lhs
    vector<int> lhs, rhs(n - 2);  // length = |lhs| + 1 or |rhs| + 1
    iota(rhs.begin(), rhs.end(), 3);
    // print tree
    for (int i = 1; i < n; i++) {
        cout << i << " " << i + 1 << "\n";
    }

    // start query
    while (q--) {
        int d; cin >> d;
        if (d == 1 + (int)rhs.size()) {
            cout << "-1 -1 -1\n";
        } else if (d > 1 + (int)rhs.size()) {
            int need = d - 1 - rhs.size();
            int u = lhs[lhs.size() - need];
            int pa = (u == lhs.front()? 2 : lhs[lhs.size() - need - 1]);
            int new_pa = (rhs.empty()? 2 : rhs.back());
            cout << u << " " << pa << " " << new_pa << "\n";
            rhs.insert(rhs.end(), lhs.end() - need, lhs.end());
            lhs.erase(lhs.end() - need, lhs.end());
        } else {
            int unneed = 1 + rhs.size() - d;
            int u = rhs[rhs.size() - unneed];
            int pa = (u == rhs.front()? 2 : rhs[rhs.size() - unneed - 1]);
            int new_pa = (lhs.empty()? 2 : lhs.back());
            cout << u << " " << pa << " " << new_pa << "\n";
            lhs.insert(lhs.end(), rhs.end() - unneed, rhs.end());
            rhs.erase(rhs.end() - unneed, rhs.end());
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

