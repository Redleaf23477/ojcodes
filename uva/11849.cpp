#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie();
    int n, m;
    while (cin >> n >> m && n && m) {
        set<int> s;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            ans += s.count(x);
        }
        cout << ans << endl;
    }
}

