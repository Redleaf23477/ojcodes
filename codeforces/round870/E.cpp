#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr int N = 5000;

LL longest_path(vector<LL> const &arr, vector<bitset<N>> const &adj_mat) {
    int n = arr.size();
    vector<int> indeg(n, 0);
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj_mat[i][j]) {
                graph[i].emplace_back(j);
                indeg[j]++;
            }
        }
    }
    queue<int> Q;
    vector<LL> path(n, 0);
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0) {
            Q.emplace(i), path[i] = arr[i];
        }
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        for (auto v : graph[u]) {
            path[v] = max(path[v], path[u] + arr[v]);
            if (--indeg[v] == 0) {
                Q.emplace(v);
            }
        }
    }

    return *max_element(path.begin(), path.end());
}

void solve() {
    int n, m; cin >> n >> m;
    vector<LL> arr(m);
    for (auto &x : arr) cin >> x;

    // assume every pair is reachable at first
    vector<bitset<N>> adj_mat(m);
    for (auto &b : adj_mat) b.set();
    // mark to false those pairs that are unreachable
    for (int i = 0; i < n; i++) {
        vector<vector<int>> rating(m);
        for (int j = 0; j < m; j++) {
            int r; cin >> r; r--;
            rating[r].emplace_back(j);
        }
        bitset<N> reachable;
        reachable.set();
        for (auto &r : rating) {
            for (auto x : r) reachable.flip(x);
            for (auto x : r) adj_mat[x] &= reachable;
        }
    }

    // dp find longest path
    cout << longest_path(arr, adj_mat) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



