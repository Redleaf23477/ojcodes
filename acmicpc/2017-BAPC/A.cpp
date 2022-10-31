#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    const double PI = acos(-1);
    double M, N, R; cin >> M >> N >> R;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    double ans = R + R + R * PI;
    for (int tmp = 0; tmp <= N; tmp++) {
        // y1 -> tmp
        double A = abs(y1 - tmp) * R / N;
        // go arc
        double rad = PI / M * abs(x1 - x2);
        double B = R * tmp / N * rad;
        // tmp -> y2
        double C = abs(y2 - tmp) * R / N;

        ans = min(ans, A + B + C);
    }
    cout << fixed << setprecision(10) << ans << "\n";
}

