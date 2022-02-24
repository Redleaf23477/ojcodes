#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

LL f(int n, vector<int> &pos) {
    int from = 0, dest = 2;
    LL ans = 0;
    for (int i = n; i > 0; i--) {
        if (pos[i] == dest) {
            from = 3 - from - dest;
            ans += (1ll<<(i-1));
        } else if (pos[i] == from) {
            dest = 3 - from - dest;
        } else {
            return -1;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n = -1;
    vector<int> pos(51, 0);
    for (int i = 0; i < 3; i++) {
        int m; cin >> m;
        while (m--) {
            int x; cin >> x;
            pos[x] = i;
            n = max(n, x);
        }
    }
    LL ans = f(n, pos);
    if (ans == -1) cout << "No\n";
    else cout << (1ll<<n) - 1 - ans << "\n";
}

