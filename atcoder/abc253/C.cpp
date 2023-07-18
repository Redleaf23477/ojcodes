#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int Q; cin >> Q;
    map<int,int> mp;
    while (Q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            mp[x]++;
        } else if (op == 2) {
            int x, c; cin >> x >> c;
            if (mp.count(x) != 0) {
                c = min(c, mp[x]);
                mp[x] -= c;
                if (mp[x] == 0) mp.erase(x);
            }
        } else {
            cout << mp.rbegin()->first - mp.begin()->first << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



