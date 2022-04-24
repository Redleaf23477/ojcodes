#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> pa(n, -1), indeg(n, 0);
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        pa[i] = x-1;
        indeg[x-1] += 1;
    }
    vector<LL> ans(n, 0);
    queue<int> q;
    for (int i = 0; i < n; i++) if (indeg[i] == 0) {
        q.emplace(i);
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        if (pa[x] != -1) {
            ans[pa[x]] += ans[x] + 1;
            if (--indeg[pa[x]] == 0) q.emplace(pa[x]);
        }
    }
    for (auto x : ans) cout << x << " ";
    cout << "\n";
}

