#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int,int> mp;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            mp[x] += 1;
        }
        int ans = -1;
        for (auto [x, cnt] : mp) {
            if (cnt >= 3) ans = x;
        }
        cout << ans << "\n";
    }
}

