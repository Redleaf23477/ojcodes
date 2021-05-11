// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
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
    int T = 1;
    for (int t = 1; t <= T; t++) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

int n, t, k;

void init() {
    cin >> n >> t >> k;
}

int query(int l, int r) { cout << "? " << l+1 << " " << r+1 << endl; int x; cin >> x; return x; }
void report(int ans) { cout << "! " << ans+1 << endl; }

void process() {
    int low = 0, high = n-1, mid, ans = -1;
    while (low <= high) {
        mid = (low + high)/2;
        int q = query(0, mid);
        int z = mid+1-q;
        debug(mid, q, z, k);
        if (z == k) ans = mid, high = mid-1;
        else if (z < k) low = mid+1;
        else high = mid-1;
    }
    assert(ans != -1);
    report(ans);
}

