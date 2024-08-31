#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL INF = 1e9;

void solve() {
    int n, m; cin >> n >> m;
    LL mx = 0;
    for (int i = 0; i < n; i++) {
        LL x; cin >> x;
        mx = max(mx, x);
    }
    for (int i = 0; i < m; i++) {
        char op; cin >> op;
        LL l, r; cin >> l >> r;
        if (l <= mx && mx <= r) {
            if (op == '+') mx++;
            else mx--;
        }
        cout << mx << " ";
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

