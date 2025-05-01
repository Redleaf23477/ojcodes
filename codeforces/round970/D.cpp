#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    size_t n; cin >> n;
    vector<int> perm(n);
    for (auto &x : perm) {
        cin >> x; x--;
    }
    string color; cin >> color;

    vector<size_t> cc_idx(n, n);
    vector<int> ans;

    auto run = [&](size_t x, size_t cc) {
        int blk = 0;
        while (cc_idx[x] == n) {
            if (color[x] == '0') blk++;
            cc_idx[x] = cc;
            x = perm[x];
        }
        ans.emplace_back(blk);
    };

    for (auto x : perm) {
        if (cc_idx[x] != n) continue;
        size_t cc = ans.size();
        run(x, cc);
    }

    for (size_t i = 0; i < n; i++) {
        cout << ans[cc_idx[i]] << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

