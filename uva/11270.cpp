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

int n, m;

void init();
void process();

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while (cin >> n >> m) {
        init();
        process();
    }
    cout.flush();
    return 0;
}

void init() {
    // n should be larger, m should be smaller
    if (n < m) swap(n, m);
}

void process() {
    vector<vector<LL>> dp(2, vector<LL>(1<<m, 0));
    int cur = 0;
    const int M = (1<<m)-1;
    dp[cur][(1<<m)-1] = 1;
    for (int r = 0; r < n; r++) for (int c = 0; c < m; c++) {
        cur ^= 1;
        // reset current dp row
        fill(dp[cur].begin(), dp[cur].end(), 0);
        // propagate from previous state s
        for (int s = 0; s < (1<<m); s++) {
            if (((s >> (m-1)) & 1) == 0) {
                // if up is empty, must place up
                dp[cur][M & (s << 1) | 1] += dp[cur^1][s];
            } else if (c != 0) {
                if ((s & 1) == 0) {
                    // if left empty, either place left
                    dp[cur][M & (s << 1) | 3] += dp[cur^1][s];
                    // or not place
                    dp[cur][M & (s << 1)] += dp[cur^1][s];
                } else {
                    // if left non-empty, don't place
                    dp[cur][M & (s << 1)] += dp[cur^1][s];
                }
            } else {
                // don't place
                dp[cur][M & (s << 1)] += dp[cur^1][s];
            }
        }
    }
    cout << dp[cur][(1<<m)-1] << endl;
}

