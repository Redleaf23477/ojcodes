#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<LL> arr(n);
    for (auto &x : arr) cin >> x;
    vector<pair<LL,LL>> stk;
    for (auto x : arr) {
        pair<LL,LL> cur(x, 1);
        while (!stk.empty() && stk.back().first > cur.first) {
            auto bk = stk.back(); stk.pop_back();
        }
        stk.emplace_back(cur);
    }
    cout << stk.back().first - stk.front().first << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

