#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    int x; cin >> x;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a >= x) continue;
        mp[a] += 1;
    }
    while (!mp.empty()) {
        auto [fac, cnt] = *mp.begin();
        if (fac >= x) {
            cout << "Yes\n"; return;
        }
        int nxt = fac + 1;
        if (cnt % nxt != 0) {
            cout << "No\n"; return;
        }
        mp[nxt] += cnt / nxt;
        mp.erase(mp.begin());
    }
    cout << "Yes\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    solve();
}

