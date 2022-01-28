// by redleaf23477
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
void solve();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    init();
    int T = 1;  // int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    cout.flush();
    return 0;
}

void init() {
}

constexpr LL MOD = 998244353;

LL fastpw(LL x, LL p, LL m = MOD) {
    LL ans = (x % m == 0? 0 : 1);
    x %= m;
    while (p > 0) {
        if (p % 2 == 1) ans = ans * x % m;
        p /= 2;
        x = x * x % m;
    }
    return ans;
}

void solve() {
    LL N, K, M; cin >> N >> K >> M;
    // calculate M^{K^N}
    if (M % MOD == 0) {
        cout << 0 << endl; 
    } else {
        // M^{MOD-1} = 1
        // M^{K^N} = M^{q(MOD-1) + r} = M^{r}
        LL r = fastpw(K, N, MOD-1);
        cout << fastpw(M, r) << endl;
    }
}

