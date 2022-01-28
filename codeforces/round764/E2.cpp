#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> arr(n);
    for (auto &x : arr) cin >> x;
    string s; cin >> s;

    vector<vector<int>> pref(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pref[i][j] = (arr[i][j] == s[j]);
        }
        for (int j = 1; j < m; j++) {
            if (pref[i][j] == 1) pref[i][j] += pref[i][j-1];
        }
    }

    /*
    cerr << "pref = " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cerr << pref[i][j] << " ";
        }
        cerr << endl;
    }
    */

    using T = tuple<int,int>;  // (idx, len)
    T no_ans(-1, -1);
    vector<int> has_ans;
    vector<T> dp(m, no_ans);
    for (int j = 1; j < m; j++) {  // character
        for (int i = 0; i < n; i++) {  // which arr
            bool found = false;
            // case1: whole prefix
            if (pref[i][j] == j+1) {
                dp[j] = T(i, j+1);
                found = true;
            }
            // case2: stop at somewhere
            else if (pref[i][j] >= 2) {
                for (int k = has_ans.size() - 1; k >= 0; k--) {
                    if (j - has_ans[k] < 2) continue;
                    if (j - pref[i][j] > has_ans[k]) break;
                    dp[j] = T(i, j - has_ans[k]);
                    found = true;
                    break;
                }
            }
            if (found) {
                has_ans.emplace_back(j);
                break;
            }
        }
        // cerr << "j = " << j << ", dp = (" << get<0>(dp[j]) << ", " << get<1>(dp[j]) << ")" << endl;
    }

    // answer or backtrace
    if (dp[m-1] == no_ans) {
        cout << -1 << endl;
    } else {
        vector<tuple<int,int>> ans;  // (index, len)
        for (int i = m-1; i >= 0; ) {
            ans.emplace_back(dp[i]);
            i -= get<1>(dp[i]);
        }


        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        int i = 1;
        for (auto [idx, len] : ans) {
            cout << i << " " << i + len - 1 << " " << idx + 1 << endl;
            i += len;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

