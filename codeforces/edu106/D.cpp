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

LL c, d, x;

void init() {
    cin >> c >> d >> x;
}

constexpr LL N2 = (LL)1e14;
constexpr LL N = (LL)1e7;

void process() {
    /*
     * gcd(a, b) = (-x +- sqrt(x*x + 4*abcd)) / 2 / d
     */
    LL ans = 0;
    for (LL sq = 2*d+x; sq <= N; sq += 2*d) {
        if ((sq*sq - x*x)%(4*c*d) != 0) continue;
        LL ab = (sq*sq - x*x) / 4 / c / d;
        LL g = (sq-x)/2/d;
        if ((x + d*g)%c != 0) continue;
        LL lcm = (x + d*g) / c;
        if (ab / g == lcm) {
            LL q = lcm / g;
            for (LL a = 1; a*a <= q; a++) {
                if (q % a == 0) {
                    LL b = ab/a;
                    ans += (a == b? 1 : 2);
                }
            }
        }
    }
    cout << ans << endl;
}

