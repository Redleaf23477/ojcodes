#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    // init sp
    const int N = 1000001;
    vector<int> sp(N, 0);
    iota(sp.begin(), sp.end(), 0);
    for (LL i = 2; i < N; i++) {
        if (sp[i] != i) continue;
        for (LL j = i * i; j < N; j += i) {
            if (sp[j] == j) sp[j] = i;
        }
    }
    // input
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) {
        cin >> x;
    }
    // search: 2 = in array, 1 = visited once
    vector<int> vis(N, 0), vis_by_me(N, 0);
    auto decomp = [&](int x) {
        vector<int> ans;
        while (x > 1) {
            if (ans.empty() || sp[x] != ans.back()) {
                ans.emplace_back(sp[x]);
            }
            x /= sp[x];
        }
        return ans;
    };
    function<void(int)> dfs = [&](int x) {
        vis_by_me[x] = 1;
        vector<int> f_arr = decomp(x);
        for (auto f : f_arr) {
            int y = x / f;
            if (vis[y] == 2) continue;
            if (vis_by_me[y] == 0) {
                vis[y] += 1;
                dfs(y);
            }
        }
    };
    function<void(int)> cleanup = [&](int x) {
        vis_by_me[x] = 0;
        vector<int> f_arr = decomp(x);
        for (auto f : f_arr) {
            int y = x / f;
            if (vis_by_me[y] == 1) {
                cleanup(y);
            }
        }
    };
    for (auto x : arr) {
        vis[x] = 2;
        dfs(x);
        cleanup(x);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (vis[i] == 2) {
            // cerr << "report " << i << endl;
            ans += 1;
        }
    }
    cout << ans - n << endl;
}

