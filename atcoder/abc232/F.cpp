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

int n;
LL x, y;
vector<LL> a, b;

void init() {
    cin >> n >> x >> y;
    a.assign(n, -1), b.assign(n, -1);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
}

constexpr int N = 18;
constexpr LL INF = (LL)1e16 * N * N + (LL)1e8 * N;

LL dp[N+1][1<<N];

void process() {
    for (int i = 0; i <= n; i++) for (int j = 0; j < (1<<n); j++) {
        dp[i][j] = INF;
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) for (int j = 0; j < (1<<n); j++) {
        if (__builtin_popcount(j) != i) continue;
        // placing a[i-1] to some position
        for (int bit = 0, cnt = 0; bit < n; cnt += ((j>>bit) & 1), bit++) {
            // place a[i-1] at b[bit]
            int right_bits = i - cnt - 1;
            dp[i][j] = min(dp[i][j], dp[i-1][j ^ (1 << bit)] + y * right_bits + x * abs(a[i-1] - b[bit])); 
        }
    }
    cout << dp[n][(1<<n)-1] << endl;
}

