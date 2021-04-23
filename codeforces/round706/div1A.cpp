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

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init() {
}

void process() {
    int n; cin >> n;
    vector<int> x, y; {
        for (int i = 0; i < 2*n; i++) {
            int _x, _y; cin >> _x >> _y;
            if (_x < 0) _x = -_x;
            if (_y < 0) _y = -_y;
            if (_x == 0) y.emplace_back(_y);
            if (_y == 0) x.emplace_back(_x);
        }
        sort(range(x)), sort(range(y));
    }
    function<double(double,double)> dist = [](double x, double y) {
        return sqrt(x*x+y*y);
    };
    double ans = 0;
    for (int i = 0; i < n; i++) ans += dist(x[i], y[i]);
    cout << fixed << setprecision(10) << ans << endl;
}

