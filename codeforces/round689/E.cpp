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

using namespace std;
using LL = long long int;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

LL k, l, r, t, x, y;

void init() {
    cin >> k >> l >> r >> t >> x >> y;
}

bool good() {
    if (y < x) {
        if (k + y <= r) {
            LL d = (k-l) / (x-y);
            return d >= t;
        } else {
            if (k - x < l) return false;
            LL d = (k-x-l) / (x-y) + 1;
            return d >= t;
        }
    } else {
        LL rest = k-l, mx = r-l;
        while (t > 0) {
            if (rest + y <= mx) rest += y;
            if (rest / x == 0) return false;
            t -= (rest / x);
            rest %= x;
        }
        return true;
    }
}

void process() {
    if (good()) cout << "Yes" << endl;
    else cout << "No" << endl;
}

