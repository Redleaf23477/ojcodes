#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
    int n; cin >> n;
    vector<int> cnt(3, 0);
    vector<int> arr(n);
    for (auto &x : arr) {
        cin >> x;
        cnt[x] += 1;
    }

    // status[x][y] = {...}: x partition has a y, index in {...}
    vector<int> status[3][3];
    // 0-partition
    for (int i = 0; i < cnt[0]; i++) {
        status[0][arr[i]].emplace_back(i);
    }
    // 1-partition
    for (int i = cnt[0]; i < cnt[0] + cnt[1]; i++) {
        status[1][arr[i]].emplace_back(i);
    }
    // 2-partition
    for (int i = cnt[0] + cnt[1]; i < n; i++) {
        status[2][arr[i]].emplace_back(i);
    }

    vector<pair<int,int>> op;
    auto do_op = [&](int u, int v) {
        op.emplace_back(u, v);
        swap(arr[u], arr[v]);
    };

    // phase 0:
    while (!status[0][2].empty() && !status[1][0].empty() && !status[2][1].empty()) {
        int u = status[0][2].back(); status[0][2].pop_back();
        int v = status[1][0].back(); status[1][0].pop_back();
        int w = status[2][1].back(); status[2][1].pop_back();
        do_op(u, w);
        do_op(u, v);
        status[0][0].emplace_back(u);
        status[1][1].emplace_back(v);
        status[2][2].emplace_back(w);
    }
    while (!status[0][1].empty() && !status[1][2].empty() && !status[2][0].empty()) {
        int u = status[0][1].back(); status[0][1].pop_back();
        int v = status[1][2].back(); status[1][2].pop_back();
        int w = status[2][0].back(); status[2][0].pop_back();
        do_op(u, w);
        do_op(v, w);
        status[0][0].emplace_back(u);
        status[1][1].emplace_back(v);
        status[2][2].emplace_back(w);
    }

    // phase 1: 0-1 swap and 2-1 swap
    for (auto x : {0, 2}) {
        while (!status[x][1].empty() && !status[1][x].empty()) {
            int u = status[x][1].back(); status[x][1].pop_back();
            int v = status[1][x].back(); status[1][x].pop_back();
            do_op(u, v);
            status[1][1].emplace_back(v);
            status[x][x].emplace_back(u);
        }
    }
    // phase 2: 0-2 swap
    if (!status[0][2].empty()) {
        int pos_1 = cnt[0];
        for (int i = 0; i < (int)status[0][2].size(); i++) {
            int u = status[0][2][i];
            int v = status[2][0][i];
            // 2-1 swap
            do_op(u, pos_1);
            // 0-1 swap
            do_op(v, u);

            pos_1 = v;
        }
        do_op(pos_1, cnt[0]);
    }

    cout << op.size() << "\n";
    assert((int)op.size() <= n);
    for (auto &[u, v] : op) {
        cout << u + 1 << " " << v + 1 << "\n";
    }

    /*
    for (auto x : arr) cerr << x << " ";
    cerr << endl;
    */
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

/*
2 2 2 1 0 0 0
--
2 2 1 2 0 0 0
2 2 0 2 1 0 0 
--
2 1 0 2 2 0 0
2 0 0 2 2 1 0
--
1 0 0 2 2 2 0
0 0 0 2 2 2 1
--
0 0 0 1 2 2 2
*/

