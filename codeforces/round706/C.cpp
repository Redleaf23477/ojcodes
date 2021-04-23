#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using LL = long long int;

void solve() {
    int n; cin >> n;
    vector<double> a, b;
    for (int i = 0; i < 2*n; i++) {
        int x, y; cin >> x >> y;
        if (x == 0) {
            if (y < 0) y = -y;
            a.emplace_back(y);
        } else {
            if (x < 0) x = -x;
            b.emplace_back(x);
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
//    reverse(b.begin(), b.end());
    double ans = 0;
    for (int i = 0; i < n; i++) {
        auto && y = a[i];
        auto && x = b[i];
        ans += sqrt(x*x+y*y);
    }
    cout << fixed << setprecision(10) << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}


