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
    constexpr LL INF = 2 * (LL)1e9;
    int n; cin >> n;
    vector<LL> A(n); {
        for (auto &x : A) cin >> x; 
    }
    vector<LL> B(n); {
        for (auto &x : B) cin >> x; 
    }
    vector<vector<LL>> dp0(n, vector<LL>(2, INF)); {
        dp0[0][0] = A[0];
        for (int i = 1; i+1 < n; i++) {
            dp0[i][0] = min(dp0[i-1][0] + A[i] + B[i-1], dp0[i-1][1] + A[i]);
            dp0[i][1] = min(dp0[i-1][0], dp0[i-1][1] + B[i-1]);
        }
        dp0[n-1][0] = min(dp0[n-2][0] + A[n-1] + B[n-2] + B[n-1], dp0[n-2][1] + A[n-1] + B[n-1]);
        dp0[n-1][1] = min(dp0[n-2][0], dp0[n-2][1] + B[n-2]);
    }
    vector<vector<LL>> dp1(n, vector<LL>(2, INF)); {
        dp1[0][1] = 0;
        for (int i = 1; i+1 < n; i++) {
            dp1[i][0] = min(dp1[i-1][0] + A[i] + B[i-1], dp1[i-1][1] + A[i]);
            dp1[i][1] = min(dp1[i-1][0], dp1[i-1][1] + B[i-1]);
        }
        dp1[n-1][0] = min(dp1[n-2][0] + A[n-1] + B[n-2], dp1[n-2][1] + A[n-1]);
        dp1[n-1][1] = min(dp1[n-2][0] + B[n-1], dp1[n-2][1] + B[n-2] + B[n-1]);
    }
    cout << min({dp0[n-1][0], dp0[n-1][1], dp1[n-1][0], dp1[n-1][1]}) << endl;
}

