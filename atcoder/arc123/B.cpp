#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n; cin >> n;
    multiset<int> A, B, C;
    for (int i = 0; i < n; i++) {
        int x; cin >> x; A.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x; B.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x; C.insert(x);
    }
    int ans = 0;
    for (auto b : B) {
        auto at = A.lower_bound(b); 
        auto ct = C.upper_bound(b);
        if (at == A.begin()) continue;
        if (ct == C.end()) continue;
        at--;
        A.erase(at);
        C.erase(ct);
        ans++;
    }
    cout << ans << "\n";
}

