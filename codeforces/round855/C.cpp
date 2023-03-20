#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    priority_queue<LL> pq;
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        if (x == 0) {
            if (!pq.empty()) {
                ans += pq.top(); pq.pop();
            }
        } else {
            pq.emplace(x);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}

