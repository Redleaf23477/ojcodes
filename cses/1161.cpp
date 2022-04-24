#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int x, n; cin >> x >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        pq.emplace(a);
    }
    LL ans = 0;
    while (pq.top() != x) {
        LL a = pq.top(); pq.pop();
        LL b = pq.top(); pq.pop();
        ans += a + b;
        pq.emplace(a + b);
    }
    cout << ans << "\n";
}

