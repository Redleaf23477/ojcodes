#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    if (n < 7) {
        vector<int> ans(n, 0);
        auto good = [&]() {
            vector<int> cnt(n, 0);
            for (auto x : ans) cnt[x] += 1;
            for (int i = 0; i < n; i++) {
                if (ans[i] != cnt[i]) return false;
            }
            return true;
        };
        function<bool(int)> dfs = [&](int i) {
            if (i == n) {
                if (good()) {
                    for (auto &x : ans) cout << x << " ";
                    cout << "\n";
                    return true;
                } else {
                    return false;
                }
            }
            bool res = false;
            for (int x = 0; x < n && !res; x++) {
                ans[i] = x;
                res = dfs(i + 1);
            }
            return res;
        };

        if (!dfs(0)) cout << -1 << "\n";
    } else {
        vector<int> ans(n, 0);
        ans[0] = n - 4;
        ans[1] = 2;
        ans[2] = 1;
        ans[n-4] = 1;
        for (auto &x : ans) cout << x << " ";
        cout << "\n";
    }
}

