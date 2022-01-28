#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, q; 
    while (cin >> n >> q) {
        vector<vector<int>> pos(1000001);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            pos[x].emplace_back(i+1);
        }
        while (q--) {
            int k, v; cin >> k >> v;
            if (pos[v].size() < k) {
                cout << 0 << "\n";
            } else {
                cout << pos[v][k-1] << "\n";
            }
        }
    }
}

