#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<bool> cut(360, false);
    cut[0] = true;
    for (int i = 0, deg = 0; i < n; i++) {
        int x; cin >> x;
        deg = (deg + x) % 360;
        cut[deg] = true;
    }
    cut.insert(cut.end(), cut.begin(), cut.end());
    int mx = 0;
    for (int i = 0, acc = 0; i < 360 * 2; i++) {
        acc++;
        if (cut[i]) {
            mx = max(mx, acc);
            acc = 0;
        }
    }
    cout << mx << "\n";
}

