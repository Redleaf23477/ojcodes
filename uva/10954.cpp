#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n;
    while (cin >> n && n) {
        priority_queue<LL, vector<LL>, greater<LL>> pq;
        for (int i = 0; i < n; i++) {
            LL x; cin >> x;
            pq.emplace(x);
        }
        LL ans = 0;
        while (pq.size() > 1) {
            LL a = pq.top(); pq.pop();
            LL b = pq.top(); pq.pop();
            a += b;
            ans += a;
            pq.emplace(a);
        }
        cout << ans << endl;
    }
}

