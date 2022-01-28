// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);
// stl
#define range(seq) seq.begin(), seq.end()


using namespace std;
using LL = long long int;
using Stopper = pair<double,double>;

constexpr double eps = 1e-9;

LL a, b, c; // three sides of triangle
vector<Stopper> arr(3);  // stoppers
vector<double> tan_half_theta(3);
/* tan_half_theta:
 *
 *       /1\
 *    a /   \ c
 *     /0___2\
 *        b
 */

inline double pw2(double x) { return x*x; }

double cal_half_tan(double a, double b, double c) {
    // theta is between a and b
    double cos_theta = (a*a + b*b - c*c) / (2.0*a*b);
    return sqrt((1-cos_theta)/(1+cos_theta));
}

double get_dist_between_center_2(double r1, double r2, double d) {
    if (d <= 0) return -7122;

    double dist_bewteen_center_2;  // square of dist between center
    if (abs(r1-r2) <= eps) dist_bewteen_center_2 = d*d;
    else dist_bewteen_center_2 = d*d + pw2(abs(r1-r2));

    return dist_bewteen_center_2;
}

bool collide(Stopper s1, Stopper s2, double d2) {  // TODO: where should I put the fucking eps
    double rsum = s1.first + s2.first;
    if (pw2(rsum) >= d2-eps) return true;
    rsum = s1.second + s2.second;
    if (pw2(rsum) >= d2-eps) return true;
    return false;
}

bool trytrysee() {
    // big fit in triangle
    vector<double> side(3); {
        for (int i = 0; i < 3; i++) side[i] = arr[i].second / tan_half_theta[i];

        /*
        for (int i = 0; i < 3; i++) {
            cerr << var(i) << var(arr[i].second) << var(side[i]) << endl;
        }
        */
    }
    double da2 = get_dist_between_center_2(arr[0].second, arr[1].second, a-side[0]-side[1]);
    double db2 = get_dist_between_center_2(arr[0].second, arr[2].second, b-side[0]-side[2]);
    double dc2 = get_dist_between_center_2(arr[1].second, arr[2].second, c-side[1]-side[2]);

    if (da2 < 0 || db2 < 0 || dc2 < 0) return false;

    // cerr << var(da2) << var(db2) << var(dc2) << endl;

    // flip the stoppers, find a config that don't overlap
    bool valid_config = false;
    for (int flip = 0; flip < 8 && !valid_config; flip++) {
        vector<Stopper> flipped_arr = arr;
        for (int b = 0; b < 3; b++) {
            if ((flip>>b)&1) swap(flipped_arr[b].first, flipped_arr[b].second);
        }
        if (!collide(flipped_arr[0], flipped_arr[1], da2)
                && !collide(flipped_arr[0], flipped_arr[2], db2)
                && !collide(flipped_arr[1], flipped_arr[2], dc2)) valid_config = true;

        /*
        if (valid_config) {
            for (int i = 0; i < 3; i++) {
                cerr << i << "=(" << arr[i].first << "," << arr[i].second << ") ";
            }
            cerr << var(flip) << endl;
        }
        */
    }
    return valid_config;
}

bool solve() {
    // (small radius, big radius)
    for (auto &s : arr) {
        if (s.first > s.second) swap(s.first, s.second);
    }
    sort(range(arr));
    // init cos_half_theta
    tan_half_theta[0] = cal_half_tan(a, b, c);
    tan_half_theta[1] = cal_half_tan(a, c, b);
    tan_half_theta[2] = cal_half_tan(b, c, a);

    bool good = false;
    do {
        good = trytrysee();
    } while (!good && next_permutation(range(arr)));

    return good;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int caseN = 0;
    while (cin >> a >> b >> c 
            >> arr[0].first >> arr[0].second 
            >> arr[1].first >> arr[1].second 
            >> arr[2].first >> arr[2].second 
            && a) {
        if (caseN != 0) cout << endl;
        a *= 2, b *= 2, c *= 2;
        cout << "Triangle number " << ++caseN << ":" << endl;
        if (solve()) cout << "All three stoppers will fit in the triangular space" << endl;
        else cout << "Stoppers will not fit in the triangular space" << endl;
    }
    cout.flush();
    return 0;
}

