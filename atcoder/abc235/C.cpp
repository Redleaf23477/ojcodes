#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; cin >> n >> q;
    map<int,vector<int>> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (mp.count(x) == 0) mp[x] = vector<int>();
        mp[x].emplace_back(i+1);
    }
    while (q--) {
        int x, k; cin >> x >> k; k -= 1;
        if (mp.count(x) == 0) {
            cout << -1 << "\n";
        } else if (mp[x].size() <= k) {
            cout << -1 << "\n";
        } else {
            cout << mp[x][k] << "\n";
        }
    }
}

