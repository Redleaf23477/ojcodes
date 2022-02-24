#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, x; cin >> n >> x;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        s.insert(a);
    }
    int ans = 0;
    while (!s.empty()) {
        auto it = s.begin();
        int mx = x - *it; 
        s.erase(it);
        auto jt = s.upper_bound(mx); 
        if (jt != s.begin()) {
            jt--;
            s.erase(jt);
        }
        ans += 1;
    }
    cout << ans << "\n";
}

