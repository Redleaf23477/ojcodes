#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

bool cmp(pair<int,int> const &lhs, pair<int,int> const &rhs) {
    if (lhs.first != rhs.first) return lhs.first > rhs.first;
    else return lhs.second > rhs.second;
}

void solve() {
    int n, m; cin >> n >> m;
    vector<pair<int,int>> choco(n), box(m);
    for (auto &[r, c] : choco) cin >> r;
    for (auto &[r, c] : choco) cin >> c;
    for (auto &[r, c] : box) cin >> r;
    for (auto &[r, c] : box) cin >> c;
    sort(choco.begin(), choco.end(), cmp);
    sort(box.begin(), box.end(), cmp);
    auto it = box.begin();
    multiset<int> usable_box;
    for (auto [r, c] : choco) {
        while (it != box.end() && it->first >= r) {
            usable_box.insert(it->second), it++;
        }
        auto lb = usable_box.lower_bound(c);
        if (lb == usable_box.end()) {
            cout << "No\n"; return;
        }
        usable_box.erase(lb);
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



