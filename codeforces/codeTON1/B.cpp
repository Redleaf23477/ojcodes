#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        LL k; cin >> k;
        map<LL,int> mp;
        for (int i = 0; i < n; i++) {
            LL x; cin >> x;
            mp[x] += 1;
        }
        bool ans = false;
        for (auto [x, cnt] : mp) {
            LL y = x - k;
            if (y == x && cnt > 1) { ans = true; break; }
            else if (mp.count(y) != 0) { ans = true; break; }
        }
        cout << (ans? "YES\n" : "NO\n");
    }
}

