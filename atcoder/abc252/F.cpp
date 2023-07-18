#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int N; cin >> N;
    LL L; cin >> L;
    priority_queue<LL, vector<LL>, greater<LL>> pq;
    for (int i = 0; i < N; i++) {
        LL x; cin >> x;
        L -= x;
        pq.emplace(x);
    }
    if (L != 0) pq.emplace(L);

    LL ans = 0;
    while (pq.size() > 1) {
        LL a = pq.top(); pq.pop();
        LL b = pq.top(); pq.pop();
        ans += a + b;
        pq.emplace(a + b);
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



