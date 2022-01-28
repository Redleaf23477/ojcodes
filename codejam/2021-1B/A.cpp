// by redleaf23477
// test3
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// variadic print template, requires c++17
template<typename Sep, typename Head, typename... Tail>
void fold_print(Sep sep, Head&& h, Tail&&... args) {
    ((std::cerr << h) << ... << (std::cerr << sep, args));
}
#ifdef REDLEAF_LOCAL
#define debug(...) do {                                     \
    std::cerr << "[DEBUG:" << __LINE__ << "] ";             \
    std::cerr << "(" << #__VA_ARGS__ ") = (";               \
    fold_print(", ", __VA_ARGS__);                          \
    std::cerr << ")\n";                                     \
    std::cerr.flush();                                      \
} while (0)
#define info(...) do {                                      \
    std::cerr << "[INFO:" << __LINE__ << "] ";              \
    fold_print(" ", __VA_ARGS__);                           \
    std::cerr << "\n";                                      \
    std::cerr.flush();                                      \
} while (0)
#else
#define debug(...) do { } while (0)
#define info(...) do { } while (0)
#endif
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);
// stl
#define range(seq) seq.begin(), seq.end()


using namespace std;
using LL = __int128;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ": ";
        init();
        process();
    }
    cout.flush();
    return 0;
}

vector<LL> arr(3);

void init() {
    for (int i = 0; i < 3; i++) { long long int x; cin >> x; arr[i] = x; }
    sort(range(arr));
}

const LL ns_per_s = 1'000'000'000ll;
const LL s_per_hr = 3600;
const LL s_per_min = 60;
const LL min_per_hr = 60;
const LL tick_per_round = 12 * 10'000'000'000ll * 360;

LL extgcd(LL a, LL b, LL &x, LL &y) {
    LL d = a;
    if (b != 0) {
        d = extgcd(b, a%b, y, x);
        y -= a / b * x;
    } else {
        x = 1, y = 0;
    }
    return d;
}

LL mod_inverse(LL a, LL m) {
    LL x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

bool run() {
    LL rot = (12 * arr[0] % tick_per_round - arr[1] + tick_per_round) % tick_per_round * mod_inverse(11, tick_per_round) % tick_per_round;
    LL ns = (arr[0] - rot + tick_per_round) % tick_per_round;

    LL h = ns / ns_per_s / s_per_hr;
    LL m = ns / ns_per_s / s_per_min % min_per_hr; 
    LL s = ns / ns_per_s % s_per_min;

    /*
    LL h2 = ((arr[0] - rot - _ns) % tick_per_round + tick_per_round) % tick_per_round / ns_per_s / s_per_hr;
    LL m2 = ((arr[1] - rot - _ns * 12) % tick_per_round + tick_per_round) % tick_per_round / (12 * ns_per_s) / s_per_min % min_per_hr;
    LL s2 = ((arr[2] - rot - _ns * 720) % tick_per_round + tick_per_round) % tick_per_round / (720 * ns_per_s) % s_per_min;
    */

    LL hr = (ns + rot) % tick_per_round;
    LL mr = (12 * ns + rot) % tick_per_round;
    LL sr = (720 * ns + rot) % tick_per_round;

    if (arr[0] != hr) return false;
    if (arr[1] != mr) return false;
    if (arr[2] != sr) return false;

    ns %= ns_per_s;

    cout << (long long)h << " " << (long long)m << " " << (long long)s << " " << (long long)ns << endl;
    return true;
}

void process() {
    do { 
        if (run()) break; 
    } while (next_permutation(range(arr)));
}

