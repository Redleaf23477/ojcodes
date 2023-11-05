#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const double eps = 1e-12;

double dist2(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return dx * dx + dy * dy;
}

double dist2_cir(double ax, double ay, double bx, double by) {
    double d2 = dist2(ax, ay, bx, by);
    return d2 / 4.0;
}

void solve() {
    double px, py; cin >> px >> py;
    double ax, ay; cin >> ax >> ay;
    double bx, by; cin >> bx >> by;
    // O -> A -> P
    double ans1 = max(dist2(0, 0, ax, ay), dist2(px, py, ax, ay));
    // O -> B -> P
    double ans2 = max(dist2(0, 0, bx, by), dist2(px, py, bx, by));
    // O -> A -> B -> P
    double ans3 = max({dist2(0, 0, ax, ay), dist2_cir(ax, ay, bx, by), dist2(px, py, bx, by)});
    // O -> B -> A -> P
    double ans4 = max({dist2(0, 0, bx, by), dist2_cir(ax, ay, bx, by), dist2(px, py, ax, ay)});

    double ans = min({ans1, ans2, ans3, ans4});
    ans = sqrt(ans);

    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
}

