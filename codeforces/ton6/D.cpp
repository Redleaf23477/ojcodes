#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<int> stk, idx;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        while (!stk.empty() && stk.back() >= x) stk.pop_back(), idx.pop_back();
        stk.emplace_back(x), idx.emplace_back(i);
    }
    /*
    for (auto x : stk) cerr << x << " ";
    cerr << endl;
    for (auto x : idx) cerr << x << " ";
    cerr << endl;
    */
    int k; cin >> k;
    vector<int> tag(n, 0);
    for (size_t i = 0, base = 0; i < stk.size(); i++) {
        int use = k / (stk[i] - base);
        if (i != 0) use = min(use, tag[idx[i - 1]]);
        if (use == 0) break;
        if (i != 0) tag[idx[i - 1]] -= use;
        tag[idx[i]] += use;
        k -= (stk[i] - base) * use;
        base = stk[i];
    }
    for (int i = n - 2; i >= 0; i--) {
        tag[i] += tag[i + 1];
    }
    for (auto x : tag) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

