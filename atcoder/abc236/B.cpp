#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i < 4 * n; i++) {
        int x; cin >> x;
        ans ^= x;
    }
    cout << ans << "\n";
    /*
    map<int,int> mp;
    for (int i = 1; i < 4*n; i++) {
        int x; cin >> x;
        mp[x] += 1;
    }
    int ans = -1;
    for (auto [x, cnt] : mp) {
        if (cnt != 4) ans = x;
    }
    cout << ans << "\n";
    */
}

