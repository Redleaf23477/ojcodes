#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<int> h(n);
    for (auto &x : h) cin >> x;
    reverse(h.begin(), h.end());

    vector<int> ans;
    vector<int> stk;
    for (int i = 0; i < n; i++) {
        ans.emplace_back(stk.size());
        while (!stk.empty() && h[i] > h[stk.back()]) stk.pop_back();
        stk.emplace_back(i);
    }
    
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T = 1;
    while (T--) solve();
}

