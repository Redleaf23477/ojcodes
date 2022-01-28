#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

#define double long double

int main() {
    ios::sync_with_stdio(false); cin.tie();
    double a, b, c, d, m, t;
    auto good = [&](double v) {
        double s = m * (a * v * v * v + b * v * v + c * v + d);
        return s < t;
    };
    while (cin >> a >> b >> c >> d >> m >> t) {
        double low = 0, high = 1e12, mid, ans = 0;
        // while (high - low > 1e-9) {
        for (int i = 0; i < 100000; i++) {
            mid = (low + high) / 2;
            if (good(mid)) {
                ans = mid, low = mid;
            } else {
                high = mid;
            }
        }
//        cerr << fixed << setprecision(5) << ans << endl;
        LL tmp = ans * 100.0;
        ans = tmp / 100.0;
        cout << fixed << setprecision(2) << ans << "\n";
    }
}

