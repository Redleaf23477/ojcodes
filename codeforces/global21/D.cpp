#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int shortest_path(vector<vector<int>> &graph) {
    int n = graph.size();
    vector<bool> vis(n, false);
    vector<int> dist(n, n);
    queue<int> q;
    q.emplace(0), dist[0] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : graph[u]) {
            if (dist[v] == n) {
                dist[v] = dist[u] + 1;
                vis[v] = true;
                q.emplace(v);
            }
        }
    }
    return dist[n-1];
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<vector<int>> graph(n);

    auto build_edge = [&](auto op) {
        stack<int> stk;
        stack<int> extreme;
        for (int i = 0; i < n; i++) {
            // pop
            while (!stk.empty() && op(arr[i], arr[stk.top()])) {
                int i = stk.top(); stk.pop();
                int ex = extreme.top(); extreme.pop();
                if (i != ex) graph[i].emplace_back(ex);
                if (!extreme.empty() && op(arr[extreme.top()], arr[ex])) {
                    extreme.top() = ex;
                }
            }
            // push
            stk.emplace(i);
            extreme.emplace(i);
        }
        while (!stk.empty()) {
            int i = stk.top(); stk.pop();
            int ex = extreme.top(); extreme.pop();
            if (i != ex) graph[i].emplace_back(ex);
            if (!extreme.empty() && op(arr[extreme.top()], arr[ex])) {
                extreme.top() = ex;
            }
        }
    };

    build_edge(less<int>());
    build_edge(greater<int>());

    cout << shortest_path(graph) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

