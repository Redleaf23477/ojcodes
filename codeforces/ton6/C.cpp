#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n);
    vector<vector<int>> exist(k);
    for (int i = 0; i < n; i++) {
        cin >> A[i]; A[i]--;
        exist[A[i]].emplace_back(i);
    }
    set<int> pos;
    for (int i = 0; i < n; i++) pos.insert(i);
    for (int i = 0; i < k; i++) {
        if (exist[i].empty()) {
            cout << 0 << " ";
        } else {
            int L = *pos.begin();
            int R = *pos.rbegin();
            cout << 2 * (R - L + 1) << " ";
            for (auto p : exist[i]) pos.erase(p);
        }
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

