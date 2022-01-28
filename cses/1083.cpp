#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<bool> vis(n+1, false);
    for (int i = 1; i < n; i++) {
        int x; cin >> x;
        vis[x] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << i << "\n";
            break;
        }
    }
}

