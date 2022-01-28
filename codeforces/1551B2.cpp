#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n);
        vector<vector<int>> pos(n+1);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            pos[arr[i]].emplace_back(i);
        }

        int lt_k_cnt = 0;
        for (auto x : arr) {
            if (pos[x].size() < k) lt_k_cnt += 1;
        }
        lt_k_cnt = lt_k_cnt / k * k;

        vector<int> ans(n, 0);
        for (auto &p : pos) {
            if (p.size() == 0) continue;
            if (p.size() >= k) {
                for (int i = 0; i < k; i++) {
                    ans[p[i]] = i+1;
                }
            } else {
                for (size_t i = 0; i < p.size() && lt_k_cnt; i++) {
                    ans[p[i]] = (lt_k_cnt - 1) % k + 1;
                    lt_k_cnt -= 1;
                }
            }
        }

        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
}

