#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<vector<int>> sets(n);
    vector<vector<int>> occur(51);
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        sets[i].resize(k);
        for (auto &x : sets[i]) {
            cin >> x;
            occur[x].emplace_back(i);
        }
    }

    int ans = 0;
    for (int bye = 1; bye <= 50; bye++) {
        if (occur[bye].size() == 0) continue;
        set<int> tmp;
        auto it = occur[bye].begin();
        for (int i = 0; i < n; i++) {
            if (it != occur[bye].end() && *it == i) {
                it++;
                continue;
            }
            tmp.insert(sets[i].begin(), sets[i].end());
        }
        ans = max((int)tmp.size(), ans);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

