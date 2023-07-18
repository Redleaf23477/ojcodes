#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    queue<pair<LL,LL>> Q; // (value, cnt)
    while (N--) {
        int op; cin >> op;
        if (op == 1) {
            LL x, c; cin >> x >> c;
            Q.emplace(x, c);
        } else {
            LL c; cin >> c;
            LL ans = 0;
            while (c > 0) {
                LL pick = min(c, Q.front().second);
                ans += Q.front().first * pick;
                c -= pick;
                Q.front().second -= pick;
                if (Q.front().second == 0) Q.pop();
            }
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



