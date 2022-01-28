// by redleaf23477
// test1
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

bool run() {
    LL ns = arr[0];
    LL h = ns / ns_per_s / s_per_hr;
    LL m = ns / ns_per_s / s_per_min % min_per_hr; 
    LL s = ns / ns_per_s % s_per_min;

    LL m2 = arr[1] / 12 / ns_per_s / s_per_min % min_per_hr;
    LL s2 = arr[2] / 720 / ns_per_s % s_per_min;

    if (m != m2) return false;
    if (s != s2) return false;

    cout << h << " " << m << " " << s << " 0" << endl;
    return true;
}

void process() {
    do { 
        if (run()) break; 
    } while (next_permutation(range(arr)));
}

