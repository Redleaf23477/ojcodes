#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int k; cin >> k;
    if (k == 1) {
        cout << "01\n"; return 0;
    }
    int vn = 1 << (k-1);
    vector<vector<int>> graph(vn);
    for (int i = 0; i < (1<<k); i++) {
        int u = i >> 1;
        int v = i & (-1 ^ (1<<(k-1)));
        graph[u].emplace_back(v);
    }
    // euler path
    vector<vector<int>::iterator> eit(vn);
    for (int i = 0; i < vn; i++) eit[i] = graph[i].begin();
    function<void(int)> dfs = [&](int u) {
        while (eit[u] != graph[u].end()) {
            int v = *eit[u]; eit[u]++;
            dfs(v);
        }
        cout << (u & 1);
    };
    dfs(0);
    cout << string(k-2, '0') << "\n";
}

