#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
using Edge = tuple<int,int>;  // (ch, idx)

void solve() {
    int n; cin >> n;
    vector<string> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<int>> self_to_self(26);
    vector<vector<Edge>> graph(26);
    vector<int> indeg(26, 0);
    for (int i = 0; i < n; i++) {
        if (arr[i].front() == arr[i].back()) {
            // self to self
            char ch = arr[i].front();
            self_to_self[ch - 'A'].emplace_back(i);
        } else {
            char f = arr[i].front(), b = arr[i].back();
            graph[f - 'A'].emplace_back(b - 'A', i);
            indeg[b - 'A'] += 1;
        }
    }

    vector<int> ans;
    bool good = true;
    stack<int> s;
    for (int i = 0; i < 26; i++) {
        if (indeg[i] == 0) s.emplace(i);
    }
    while (good && !s.empty()) {
        int f = s.top(); s.pop();
        // self to self first
        for (; !self_to_self[f].empty(); self_to_self[f].pop_back()) {
            ans.emplace_back(self_to_self[f].back());
        }
        // to next character
        if (graph[f].size() > 1) good = false;
        else if (graph[f].size() == 1) {
            auto [ch_n, idx] = graph[f][0];
            indeg[ch_n]--;
            s.emplace(ch_n);
            ans.emplace_back(idx);
            if (indeg[ch_n] != 0) good = false;
        }
    }
    if (ans.size() != arr.size()) good = false;

    auto check = [&](vector<int> &ans) {
        vector<bool> vis(26, false);
        char prv = 'x';
        for (auto s : ans) for (auto c : arr[s]) {
            if (c != prv) {
                if (vis[c - 'A']) return false;
                vis[c - 'A'] = true;
                prv = c;
            }
        }
        return true;
    };
    auto print = [&](vector<int> &ans) {
        for (auto x : ans) cout << arr[x];
        cout << "\n";
    };

    if (good) good = check(ans);

    if (good) print(ans);
    else cout << "IMPOSSIBLE\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        solve();
    }
}

