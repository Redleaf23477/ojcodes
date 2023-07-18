#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

void solve() {
    int x, y; cin >> x >> y;
    double dist = sqrt(x * x + y * y);
    cout << fixed << setprecision(10) << x / dist << " " << y / dist << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}



