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

void init() {
}

void process() {
    LL n, x; cin >> n >> x;
    vector<LL> money(n); {
        for (int i = 0; i < n; i++) cin >> money[i];
    }
    if (n == 1) {
        cout << x << endl; return;
    }
    vector<LL> digits(n); {
        for (int i = n-1; i >= 0; i--) {
            digits[i] = x / money[i];
            x %= money[i];
        }
    }
    vector<vector<LL>> dp(n, vector<LL>(2, 0)); {
        // dp[i][0] = no cmoneyy; dp[i][1] = cmoneyy
        dp[0][0] = digits[0], dp[0][1] = money[1] / money[0] - digits[0];
        for (int i = 1; i + 1 < n; i++) {
            dp[i][0] = min(dp[i-1][0] + digits[i], dp[i-1][1] + 1 + digits[i]);
            dp[i][1] = min(dp[i-1][0] + money[i+1] / money[i] - digits[i], dp[i-1][1] + money[i+1] / money[i] - digits[i] - 1);
        }
        dp[n-1][0] = min(dp[n-2][0] + digits[n-1], dp[n-2][1] + 1 + digits[n-1]);
    }
    cout << dp[n-1][0] << endl;
}

