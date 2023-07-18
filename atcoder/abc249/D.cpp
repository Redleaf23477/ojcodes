#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n; 
    map<LL,LL> A;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        A[x]++;
    }
    LL mx = A.rbegin()->first;
    LL ans = 0;
    for (auto it = A.begin(); it != A.end(); it++) {
        for (auto jt = A.begin(); jt != A.end(); jt++) {
            LL val = it->first * jt->first;
            if (val > mx) break;
            auto kt = A.find(val);
            if (kt != A.end()) {
                ans += it->second * jt->second * kt->second;
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    //     int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



