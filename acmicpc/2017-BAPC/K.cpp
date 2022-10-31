#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    // edge: winner -> loser
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        string line; cin >> line;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (line[j] == '1') graph[i].emplace_back(j);
            else graph[j].emplace_back(i);
        }
    }
    // construct answer
    vector<int> ans;
    vector<bool> vis(n, false);
    queue<int> Q; Q.emplace(0), vis[0] = true;
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        ans.emplace_back(u);
        for (auto v : graph[u]) {
            if (!vis[v]) {
                Q.emplace(v);
                vis[v] = true;
            }
        }
    }
    // print answer
    if (ans.size() != n) {
        cout << "impossible\n";
    } else {
        reverse(ans.begin(), ans.end());
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}

