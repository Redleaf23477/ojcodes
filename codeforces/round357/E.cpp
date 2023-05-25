#include <bits/stdc++.h>
using namespace std;
using LL = long long int;

const double PI = acos(-1);
const double EPS = 1e-8;

double sq(double x) { return x * x; }
__int128 sq128(__int128 x) { return x * x; }

bool too_far(LL x, LL y, LL r, LL run_dist) {
    return sq128(x) + sq128(y) >= sq128(r + run_dist);
}

bool in_circle(LL x, LL y, LL r) {
    return sq128(r) >= sq128(x) + sq128(y);
}

void add_seg(LL x, LL y, LL r, double run_dist, set<tuple<double,double>> &seg) {
    // get theta
    double r2 = sq(r);
    double d2 = sq(x) + sq(y), d = sqrt(d2);
    double a2 = d2 - r2, a = sqrt(a2);
    double theta;
    if (sq128(x) + sq128(y) - sq128(r) <= sq128(run_dist)) {
        theta = asin(r / d);
    } else {
        theta = acos((d2 + sq(run_dist) - r2) / (2 * d * run_dist));
    }

    // add to set
    double center = atan2(y, x);
    double L = center - theta, R = center + theta;
    /*
    cerr << "center = " << center / PI << " * PI" << endl;
    cerr << "theta = " << theta / PI << " * PI" << endl;
    cerr << "L = " << L / PI << " * PI; R = " << R / PI << " * PI" << endl;
    */
    if (L + EPS < -PI) {
        seg.insert(make_tuple(L + 2 * PI, PI));
        seg.insert(make_tuple(-PI, R));
    } else if (R > PI + EPS) {
        seg.insert(make_tuple(L, PI));
        seg.insert(make_tuple(-PI, R - 2 * PI));
    } else {
        seg.insert(make_tuple(L, R));
    }
}

double union_length(set<tuple<double,double>> const &seg) {
    double sum = 0, R = -PI;
    for (auto [l, r] : seg) {
        l = max(l, R);
        if (R < r) {
            sum += r - l;
            R = r;
        }
    }
    return sum;
}

void solve() {
    LL x0, y0, v, T; cin >> x0 >> y0 >> v >> T;
    LL run_dist = v * T;
    int n; cin >> n;
    vector<tuple<LL,LL,LL>> cir(n);
    for (auto &[x, y, r] : cir) {
        cin >> x >> y >> r;
        x -= x0, y -= y0;
    }
    set<tuple<double,double>> seg;
    bool in_shadow = false;
    for (auto [x, y, r] : cir) {
        if (in_circle(x, y, r)) {
            in_shadow = true;
        } else if (!too_far(x, y, r, run_dist)) { // else if (dist2 <= sq(x) + sq(y) + EPS) {
            add_seg(x, y, r, run_dist, seg);
        }
    }
    /*
    cerr << "seg: " << endl;
    for (auto [L, R] : seg) {
        cerr << L << " " << R << " " << abs(R - L) << endl;
    }
    */
    if (in_shadow) {
        cout << 1 << "\n";
    } else {
        cout << fixed << setprecision(8) << union_length(seg) / (2 * PI) << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    while (T--) {
        solve();
    }
}




