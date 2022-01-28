#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    vector<vector<int>> pos(n+2);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i]].emplace_back(i);
    }
    for (auto &x : pos) {
        reverse(x.begin(), x.end());
    }

    size_t i = 0;
    vector<int> ans;
    vector<bool> vis(n+1, false);
    while (i < arr.size()) {
        if (pos[0].empty()) {
            ans.emplace_back(0);
            pos[arr[i]].pop_back();
            i++;
            continue;
        }
        for (int mex = 0; mex <= n; mex++) {
            if (vis[mex]) continue;
            if (!pos[mex].empty()) {
                while (arr[i] != mex) {
                    vis[arr[i]] = true;
                    pos[arr[i]].pop_back();
                    i++;
                }
                pos[mex].pop_back();
                i++;
            } else {
                ans.emplace_back(mex);
                for (int i = 0; i < mex; i++) vis[i] = false;
                break;
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

