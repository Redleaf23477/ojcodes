#include <bits/stdc++.h>
using namespace std;
using LL = long long int;
constexpr double PI = acos(-1);

void solve() {
    double x, y, d; cin >> x >> y >> d;
    double theta = PI * d / 180;
    double s = sin(theta), c = cos(theta);
    double x2 = x * c - y * s;
    double y2 = x * s + y * c;
    cout << fixed << setprecision(10) << x2 << " " << y2 << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
//    int T; cin >> T;
    int T = 1;
    while (T--) {
        solve();
    }
}



