#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    vector<int> pos(n+1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        pos[x] = i;
    }
    int ans = 0, p = n+1;
    for (int i = 1; i <= n; i++) {
        if (pos[i] < p) ans++;
        p = pos[i];
    }
    cout << ans << endl;
}

