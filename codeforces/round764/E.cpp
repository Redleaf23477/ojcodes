#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> arr(n);
    for (auto &x : arr) cin >> x;
    string s; cin >> s;

    if (m == 1) {
        cout << -1 << endl;
        return;
    } else if (m == 2) {
        for (int i = 0; i < n; i++) {
            if (arr[i] == s) {
                cout << 1 << " " << m << " " << i+1 << endl;
                return;
            }
        }
        cout << -1 << endl;
        return;
    }

    using T3 = tuple<int,int,int>;  // (l, r, idx)
    using T4 = tuple<int,int,int,int>;  
    map<string, T3> dict;
    for (int idx = 0; idx < n; idx++) {
        auto &str = arr[idx];
        // 2-mer
        for (size_t i = 0; i + 2 <= str.size(); i++) {
            dict[str.substr(i, 2)] = make_tuple(i+1, i+2, idx+1);
        }
        // 3-mer
        for (size_t i = 0; i + 3 <= str.size(); i++) {
            dict[str.substr(i, 3)] = make_tuple(i+1, i+3, idx+1);
        }
    }

    T4 no_ans(-1, -1, -1, -1);
    vector<T4> dp(m, no_ans);
    if (dict.count(s.substr(0, 2)) != 0) {
        auto [a, b, c] = dict[s.substr(0, 2)];
        dp[1] = make_tuple(a, b, c, -1);
    }
    if (dict.count(s.substr(0, 3)) != 0) {
        auto [a, b, c] = dict[s.substr(0, 3)];
        dp[2] = make_tuple(a, b, c, -1);
    }
    for (int j = 3; j < m; j++) {  // character
        // 2-mer
        if (dp[j-2] != no_ans) {
            string sub = s.substr(j-1, 2);
            if (dict.count(sub) != 0) {
                auto [a, b, c] = dict[sub];
                dp[j] = make_tuple(a, b, c, j-2);
            }
        }
        if (dp[j-1] != no_ans) {
            string sub = s.substr(j-1, 2);
            if (dict.count(sub) != 0) {
                auto [a, b, c] = dict[sub];
                dp[j] = make_tuple(a, b, c, j-1);
            }
        }
        // 3-mer
        if (dp[j-3] != no_ans) {
            string sub = s.substr(j-2, 3);
            if (dict.count(sub) != 0) {
                auto [a, b, c] = dict[sub];
                dp[j] = make_tuple(a, b, c, j-3);
            }
        }
    }

    // answer or backtrace
    if (dp[m-1] == no_ans) {
        cout << -1 << endl;
    } else {
        vector<tuple<int,int,int>> ans;
        for (int i = m-1; i >= 0; ) {
            auto [l, r, idx, to] = dp[i];
            ans.emplace_back(l, r, idx);
            i = to;
        }


        reverse(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for (auto [l, r, idx] : ans) {
            cout << l << " " << r << " " << idx << endl;
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

