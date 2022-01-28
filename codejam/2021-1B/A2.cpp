// by redleaf23477
// test2
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
using LL = long long int;

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
    for (int i = 0; i < 3; i++) cin >> arr[i];
    sort(range(arr));
}

const LL ns_per_s = 1000000000;
const LL s_per_hr = 3600;
const LL s_per_min = 60;
const LL min_per_hr = 60;
const LL tick_per_round = 12 * 10000000000ll * 360;

bool run(LL day_sec) {
    LL h = day_sec / s_per_hr;
    LL m = day_sec / s_per_min % min_per_hr;
    LL s = day_sec % s_per_min;
    LL ns = day_sec * ns_per_s;

    LL dh = (ns - arr[0] + tick_per_round) % tick_per_round;
    LL dm = (ns*12 - arr[1] + tick_per_round) % tick_per_round;
    LL ds = (ns*720 - arr[2] + tick_per_round) % tick_per_round;

    if (dh == dm && dm == ds) {
        debug(dh);
        cout << h << " " << m << " " << s << " 0" << endl;
        return true;
    }
    return false;
}

bool run() {
    for (int s = 0; s < 60*60*24; s++) {
        run(s);
        // if (run(s)) return true;
    }
    return false;
}

void process() {
    do { 
        if (run()) break; 
    } while (next_permutation(range(arr)));
}

