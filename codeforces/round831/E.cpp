#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 1; i < n; i++) {
        int pa; cin >> pa; pa--;
        tree[pa].emplace_back(i);
    }
    vector<int> use_me(n, 0);
    vector<int> give_up_me(n, 0);
    function<void(int)> dfs = [&](int u) {
        use_me[u] = 1;
        for (auto v : tree[u]) {
            dfs(v);
            give_up_me[u] += max(give_up_me[v], use_me[v]);
            use_me[u] = max(use_me[u], 1 + use_me[v]);
        }
    };
    dfs(0);
    cout << max(give_up_me[0], use_me[0]) << "\n";
}

