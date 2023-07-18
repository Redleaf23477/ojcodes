#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> pre(n), in(n);
    for (auto &x : pre) cin >> x;
    for (auto &x : in) cin >> x;
    vector<int> inpos(n + 1);
    for (int i = 1; i < n; i++) {
        inpos[in[i]] = i;
    }
    vector<pair<int,int>> ans(n, make_pair(0, 0));

    int cursor = 0;
    bool good = (pre.front() == 1);
    function<int(int,int)> build_tree = [&](int l, int r) {
        if (r < l) return 0;

        int root = pre[cursor++];
        if (l <= inpos[root] && inpos[root] <= r) {
            ans[root - 1].first = build_tree(l, inpos[root] - 1);
            ans[root - 1].second = build_tree(inpos[root] + 1, r);
            return root;
        } else {
            good = false;
            return -1;
        }
    };
    build_tree(0, n-1);

    if (good) {
        for (auto [l, r] : ans) {
            cout << l << " " << r << "\n";
        }
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



