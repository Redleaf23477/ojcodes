#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

vector<int> get_bfs(int r, vector<vector<int>> &tree) {
    vector<int> ans;
    vector<bool> vis(tree.size(), false);
    queue<int> q({r});
    vis[r] = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans.emplace_back(u);
        for (auto v : tree[u]) {
            if (!vis[v]) {
                q.emplace(v);
                vis[v] = true;
            }
        }
    }
    return ans;
}

vector<int> get_dfs(int r, vector<vector<int>> &tree) {
    vector<int> ans;
    function<void(int,int)> dfs = [&](int u, int pa) {
        ans.emplace_back(u);
        for (auto v : tree[u]) {
            if (v == pa) continue;
            dfs(v, u);
        }
    };
    dfs(r, r);
    return ans;
}

void solve(int n) {
    vector<int> bfs(n), dfs(n);
    for (auto &b : bfs) { cin >> b; b--; }
    for (auto &d : dfs) { cin >> d; d--; }

    vector<int> pos_in_bfs(n), pos_in_dfs(n);
    for (int i = 0; i < n; i++) {
        pos_in_bfs[bfs[i]] = i;
        pos_in_dfs[dfs[i]] = i;
    }

    vector<int> bfs_level(n);
    bfs_level[bfs[0]] = 0;
    for (int i = 1, lv = 1; i < n; i++) {
        if (pos_in_dfs[bfs[i]] < pos_in_dfs[bfs[i-1]]) {
            lv++;
        }
        bfs_level[bfs[i]] = lv;
    }

    /*
    for (auto b : bfs) {
        cerr << b+1 << ": lv = " << bfs_level[b] << endl;
    }
    */

    vector<vector<int>> tree(n);

    stack<int> stk;
    for (auto d : dfs) {
        if (stk.empty()) {
            stk.emplace(d);
        } else {
            while (bfs_level[stk.top()] + 1 != bfs_level[d]) stk.pop();
            int u = stk.top();
            tree[u].emplace_back(d);
            stk.emplace(d);
        }
    }

    vector<vector<int>> test(n);

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ":";
        sort(tree[i].begin(), tree[i].end());
        for (auto j : tree[i]) {
            cout << " " << j + 1;
            test[i].emplace_back(j);
            test[j].emplace_back(i);
        }
        cout << "\n";
    }

    auto b = get_bfs(bfs_order.front(), test);
    auto d = get_dfs(dfs_order.front(), test);
    assert(b == bfs_order && d == dfs_order);
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n;
    while (cin >> n) {
        solve(n);
    }
}

