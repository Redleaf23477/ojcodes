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
vector<int> zero, one;

void init() {
    cin >> n;
    zero.emplace_back(-1), one.emplace_back(-1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x == 0) zero.emplace_back(i);
        else one.emplace_back(i);
    }
}

void process() {
    vector<vector<int>> dp(zero.size(), vector<int>(one.size(), 2*n*n));

    dp[0][0] = 0;
    for (size_t i = 1; i < zero.size(); i++) {
        dp[i][0] = 0;
        for (size_t j = 1; j < one.size(); j++) {
            dp[i][j] = min(dp[i-1][j], dp[i-1][j-1] + abs(zero[i]-one[j]));
        }
    }

    int ans = 2*n*n;
    for (size_t i = 0; i < zero.size(); i++)
        ans = min(ans, dp[i].back());
    cout << ans << endl;
}
